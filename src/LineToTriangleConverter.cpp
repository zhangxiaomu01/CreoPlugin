// LineToTriangleConverter.cpp
#include "pch.h"

#include "LineToTriangleConverter.h"
#include <cmath>
#include <unordered_map>
#include <vector>


double LineToTriangleConverter::NDS_PI = 3.14159265351;

// 向量运算实现
LineToTriangleConverter::Vec3 LineToTriangleConverter::subtract(const Vec3& a, const Vec3& b) {
    return { a[0] - b[0], a[1] - b[1], a[2] - b[2] };
}

LineToTriangleConverter::Vec3 LineToTriangleConverter::add(const Vec3& a, const Vec3& b) {
    return { a[0] + b[0], a[1] + b[1], a[2] + b[2] };
}

LineToTriangleConverter::Vec3 LineToTriangleConverter::multiply(const Vec3& v, float scalar) {
    return { v[0] * scalar, v[1] * scalar, v[2] * scalar };
}

LineToTriangleConverter::Vec3 LineToTriangleConverter::cross(const Vec3& a, const Vec3& b) {
    return {
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0]
    };
}

float LineToTriangleConverter::length(const Vec3& v) {
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

LineToTriangleConverter::Vec3 LineToTriangleConverter::normalize(const Vec3& v) {
    float len = length(v);
    if (len == 0.0f) return { 0.0f, 0.0f, 0.0f };
    return { v[0] / len, v[1] / len, v[2] / len };
}

// 计算三角形面法线
LineToTriangleConverter::Vec3 LineToTriangleConverter::ComputeFaceNormal(
    const Vec3& v1, const Vec3& v2, const Vec3& v3) {
    Vec3 edge1 = subtract(v2, v1);
    Vec3 edge2 = subtract(v3, v1);
    Vec3 normal = cross(edge1, edge2);
    return normalize(normal);
}

// 计算顶点法线（平均相邻面法线）
void LineToTriangleConverter::ComputeVertexNormals(
    const std::vector<float>& vertices,
    const std::vector<unsigned int>& indices,
    std::vector<float>& normals) {

    size_t vertexCount = vertices.size() / 3;
    normals.resize(vertices.size(), 0.0f); // 初始化为0

    // 临时存储每个顶点的累积法线和计数
    std::vector<Vec3> tempNormals(vertexCount, { 0.0f, 0.0f, 0.0f });
    std::vector<int> faceCount(vertexCount, 0);

    // 遍历所有三角形，累加面法线到顶点
    for (size_t i = 0; i < indices.size(); i += 3) {
        unsigned int i1 = indices[i];
        unsigned int i2 = indices[i + 1];
        unsigned int i3 = indices[i + 2];

        // 获取顶点位置
        Vec3 v1 = { vertices[i1 * 3], vertices[i1 * 3 + 1], vertices[i1 * 3 + 2] };
        Vec3 v2 = { vertices[i2 * 3], vertices[i2 * 3 + 1], vertices[i2 * 3 + 2] };
        Vec3 v3 = { vertices[i3 * 3], vertices[i3 * 3 + 1], vertices[i3 * 3 + 2] };

        // 计算面法线
        Vec3 faceNormal = ComputeFaceNormal(v1, v2, v3);

        // 累加到三个顶点
        tempNormals[i1] = add(tempNormals[i1], faceNormal);
        tempNormals[i2] = add(tempNormals[i2], faceNormal);
        tempNormals[i3] = add(tempNormals[i3], faceNormal);

        faceCount[i1]++;
        faceCount[i2]++;
        faceCount[i3]++;
    }

    // 平均化并存储到输出数组
    for (size_t i = 0; i < vertexCount; ++i) {
        if (faceCount[i] > 0) {
            Vec3 avgNormal = multiply(tempNormals[i], 1.0f / faceCount[i]);
            avgNormal = normalize(avgNormal);

            normals[i * 3] = avgNormal[0];
            normals[i * 3 + 1] = avgNormal[1];
            normals[i * 3 + 2] = avgNormal[2];
        }
        else {
            // 如果没有相邻面，使用默认法线
            normals[i * 3] = 0.0f;
            normals[i * 3 + 1] = 1.0f;
            normals[i * 3 + 2] = 0.0f;
        }
    }
}

void LineToTriangleConverter::AddLineSegmentToMesh(
    const float* p1, const float* p2, float radius, int segments, 
    std::vector<float>& outVertices, std::vector<unsigned int>& outIndices, unsigned int& vertexOffset)
{
    // 将float指针转换为Vec3用于计算
    Vec3 v1 = { p1[0], p1[1], p1[2] };
    Vec3 v2 = { p2[0], p2[1], p2[2] };

    Vec3 direction = subtract(v2, v1);
    float lineLength = length(direction);

    if (lineLength == 0.0f) {
        return; // 跳过零长度线段
    }

    direction = normalize(direction);

    // 找到与方向垂直的基准向量
    Vec3 baseVec;
    if (std::abs(direction[0]) > 0.1f || std::abs(direction[1]) > 0.1f) {
        baseVec = { -direction[1], direction[0], 0.0f };
    }
    else {
        baseVec = { 0.0f, -direction[2], direction[1] };
    }

    baseVec = normalize(baseVec);

    // 计算第二个垂直向量
    Vec3 baseVec2 = cross(direction, baseVec);
    baseVec2 = normalize(baseVec2);

    // 生成圆柱体截面顶点
    std::vector<Vec3> startVertices(segments);
    std::vector<Vec3> endVertices(segments);

    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * static_cast<float>(NDS_PI) * i / segments;
        Vec3 offset = add(
            multiply(baseVec, radius * std::cos(angle)),
            multiply(baseVec2, radius * std::sin(angle))
        );

        startVertices[i] = add(v1, offset);
        endVertices[i] = add(v2, offset);
    }

    // 保存当前顶点偏移量
    unsigned int currentOffset = vertexOffset;

    // 添加起点端面中心 (索引 currentOffset)
    outVertices.push_back(v1[0]);
    outVertices.push_back(v1[1]);
    outVertices.push_back(v1[2]);

    // 添加起点圆周顶点 (索引 currentOffset + 1 到 currentOffset + segments)
    for (const auto& vertex : startVertices) {
        outVertices.push_back(vertex[0]);
        outVertices.push_back(vertex[1]);
        outVertices.push_back(vertex[2]);
    }

    // 添加终点端面中心 (索引 currentOffset + segments + 1)
    outVertices.push_back(v2[0]);
    outVertices.push_back(v2[1]);
    outVertices.push_back(v2[2]);

    // 添加终点圆周顶点 (索引 currentOffset + segments + 2 到 currentOffset + 2*segments + 1)
    for (const auto& vertex : endVertices) {
        outVertices.push_back(vertex[0]);
        outVertices.push_back(vertex[1]);
        outVertices.push_back(vertex[2]);
    }

    // 生成侧面三角形索引
    for (int i = 0; i < segments; ++i) {
        int next_i = (i + 1) % segments;

        // 起点圆周顶点索引
        unsigned int start_i = currentOffset + 1 + i;
        unsigned int start_next = currentOffset + 1 + next_i;

        // 终点圆周顶点索引
        unsigned int end_i = currentOffset + segments + 2 + i;
        unsigned int end_next = currentOffset + segments + 2 + next_i;

        // 侧面第一个三角形 (start_i -> end_i -> start_next)
        outIndices.push_back(start_i);
        outIndices.push_back(end_i);
        outIndices.push_back(start_next);

        // 侧面第二个三角形 (start_next -> end_i -> end_next)
        outIndices.push_back(start_next);
        outIndices.push_back(end_i);
        outIndices.push_back(end_next);
    }

    // 生成端面三角形索引
    unsigned int startCenterIndex = currentOffset; // 起点中心索引
    unsigned int endCenterIndex = currentOffset + segments + 1; // 终点中心索引

    for (int i = 0; i < segments; ++i) {
        int next_i = (i + 1) % segments;

        // 起点圆周顶点索引
        unsigned int start_i = currentOffset + 1 + i;
        unsigned int start_next = currentOffset + 1 + next_i;

        // 终点圆周顶点索引
        unsigned int end_i = currentOffset + segments + 2 + i;
        unsigned int end_next = currentOffset + segments + 2 + next_i;

        // 起点端面三角形 (逆时针: 中心 -> 当前点 -> 下一点)
        outIndices.push_back(startCenterIndex);
        outIndices.push_back(start_i);
        outIndices.push_back(start_next);

        // 终点端面三角形 (顺时针: 中心 -> 下一点 -> 当前点)
        outIndices.push_back(endCenterIndex);
        outIndices.push_back(end_next);
        outIndices.push_back(end_i);
    }

    // 更新顶点偏移量
    vertexOffset += 2 + 2 * segments; // 两个中心点 + 两圈圆周顶点
}

// 单条线段转换为圆柱体
LineToTriangleConverter::MeshData LineToTriangleConverter::convertLineToCylinder(
    const Vec3& p1, const Vec3& p2, float radius, int segments) {
    MeshData mesh;

    Vec3 direction = subtract(p2, p1);
    float lineLength = length(direction);

    if (lineLength == 0.0f) {
        return mesh; // 返回空的mesh
    }

    direction = normalize(direction);

    // 找到与方向垂直的基准向量
    Vec3 baseVec;
    if (std::abs(direction[0]) > 0.1f || std::abs(direction[1]) > 0.1f) {
        baseVec = { -direction[1], direction[0], 0.0f };
    }
    else {
        baseVec = { 0.0f, -direction[2], direction[1] };
    }

    baseVec = normalize(baseVec);

    // 计算第二个垂直向量
    Vec3 baseVec2 = cross(direction, baseVec);
    baseVec2 = normalize(baseVec2);

    // 生成圆柱体截面顶点
    std::vector<Vec3> startVertices(segments);
    std::vector<Vec3> endVertices(segments);

    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * NDS_PI * i / segments;
        Vec3 offset = add(
            multiply(baseVec, radius * std::cos(angle)),
            multiply(baseVec2, radius * std::sin(angle))
        );

        startVertices[i] = add(p1, offset);
        endVertices[i] = add(p2, offset);
    }

    // 构建顶点数组 (每3个float一个顶点)
    // 顶点顺序: 起点端面中心, 起点圆顶点, 终点端面中心, 终点圆顶点
    mesh.vertices.reserve((2 + 2 * segments) * 3); // 两个中心点 + 圆周顶点

    // 添加起点端面中心 (索引 0)
    mesh.vertices.push_back(p1[0]);
    mesh.vertices.push_back(p1[1]);
    mesh.vertices.push_back(p1[2]);

    // 添加起点圆周顶点 (索引 1 到 segments)
    for (const auto& vertex : startVertices) {
        mesh.vertices.push_back(vertex[0]);
        mesh.vertices.push_back(vertex[1]);
        mesh.vertices.push_back(vertex[2]);
    }

    // 添加终点端面中心 (索引 segments + 1)
    mesh.vertices.push_back(p2[0]);
    mesh.vertices.push_back(p2[1]);
    mesh.vertices.push_back(p2[2]);

    // 添加终点圆周顶点 (索引 segments + 2 到 2*segments + 1)
    for (const auto& vertex : endVertices) {
        mesh.vertices.push_back(vertex[0]);
        mesh.vertices.push_back(vertex[1]);
        mesh.vertices.push_back(vertex[2]);
    }

    // 构建索引数组
    mesh.indices.reserve(12 * segments); // 每个segment有4个三角形，每个三角形3个索引

    // 生成侧面三角形索引
    for (int i = 0; i < segments; ++i) {
        int next_i = (i + 1) % segments;

        // 起点圆周顶点索引
        unsigned int start_i = 1 + i;
        unsigned int start_next = 1 + next_i;

        // 终点圆周顶点索引
        unsigned int end_i = segments + 2 + i;
        unsigned int end_next = segments + 2 + next_i;

        // 侧面第一个三角形 (start_i -> end_i -> start_next)
        mesh.indices.push_back(start_i);
        mesh.indices.push_back(end_i);
        mesh.indices.push_back(start_next);

        // 侧面第二个三角形 (start_next -> end_i -> end_next)
        mesh.indices.push_back(start_next);
        mesh.indices.push_back(end_i);
        mesh.indices.push_back(end_next);
    }

    // 生成端面三角形索引
    unsigned int startCenterIndex = 0; // 起点中心索引
    unsigned int endCenterIndex = segments + 1; // 终点中心索引

    for (int i = 0; i < segments; ++i) {
        int next_i = (i + 1) % segments;

        // 起点圆周顶点索引
        unsigned int start_i = 1 + i;
        unsigned int start_next = 1 + next_i;

        // 终点圆周顶点索引
        unsigned int end_i = segments + 2 + i;
        unsigned int end_next = segments + 2 + next_i;

        // 起点端面三角形 (逆时针: 中心 -> 当前点 -> 下一点)
        mesh.indices.push_back(startCenterIndex);
        mesh.indices.push_back(start_i);
        mesh.indices.push_back(start_next);

        // 终点端面三角形 (顺时针: 中心 -> 下一点 -> 当前点)
        mesh.indices.push_back(endCenterIndex);
        mesh.indices.push_back(end_next);
        mesh.indices.push_back(end_i);
    }

    // 计算顶点法线
    ComputeVertexNormals(mesh.vertices, mesh.indices, mesh.normals);

    return mesh;
}

// 批量转换多条线段
LineToTriangleConverter::MeshData LineToTriangleConverter::convertLinesToCylinders(
    const std::vector<std::pair<Vec3, Vec3>>& lines,
    float radius, int segments) {

    MeshData combinedMesh;

    for (const auto& line : lines) {
        MeshData lineMesh = convertLineToCylinder(line.first, line.second, radius, segments);

        if (lineMesh.vertices.empty()) continue;

        // 保存当前combinedMesh的顶点数量，用于索引偏移
        unsigned int vertexOffset = static_cast<unsigned int>(combinedMesh.vertices.size() / 3);

        // 添加顶点
        combinedMesh.vertices.insert(
            combinedMesh.vertices.end(),
            lineMesh.vertices.begin(),
            lineMesh.vertices.end()
        );

        // 添加法线
        combinedMesh.normals.insert(
            combinedMesh.normals.end(),
            lineMesh.normals.begin(),
            lineMesh.normals.end()
        );

        // 添加索引（应用偏移）
        for (unsigned int index : lineMesh.indices) {
            combinedMesh.indices.push_back(index + vertexOffset);
        }
    }

    return combinedMesh;
}

LineToTriangleConverter::MeshData LineToTriangleConverter::ConvertLineSegmentsToCylinders(
    const std::vector<float>& lineVertices, const std::vector<unsigned int>& lineIndices, float radius, int segments)
{
    MeshData mesh;

    // 验证输入数据
    if (lineVertices.size() % 3 != 0) {
        // 顶点数量不是3的倍数
        return mesh;
    }

    if (lineIndices.size() % 2 != 0) {
        // 索引数量不是2的倍数
        return mesh;
    }

    // 预分配内存
    size_t lineCount = lineIndices.size() / 2;
    size_t verticesPerLine = 2 + 2 * segments; // 两个中心点 + 两圈圆周顶点
    size_t indicesPerLine = 12 * segments; // 每个segment有4个三角形，每个三角形3个索引

    mesh.vertices.reserve(lineCount * verticesPerLine * 3);
    mesh.indices.reserve(lineCount * indicesPerLine);

    unsigned int vertexOffset = 0;

    // 处理每条线段
    for (size_t i = 0; i < lineIndices.size(); i += 2) {
        unsigned int idx1 = lineIndices[i];
        unsigned int idx2 = lineIndices[i + 1];

        // 检查索引是否有效
        if (idx1 * 3 + 2 >= lineVertices.size() || idx2 * 3 + 2 >= lineVertices.size()) {
            continue; // 跳过无效索引
        }

        const float* p1 = &lineVertices[idx1 * 3];
        const float* p2 = &lineVertices[idx2 * 3];

        AddLineSegmentToMesh(p1, p2, radius, segments, mesh.vertices, mesh.indices, vertexOffset);
    }

    // 计算顶点法线
    ComputeVertexNormals(mesh.vertices, mesh.indices, mesh.normals);

    return mesh;
}
