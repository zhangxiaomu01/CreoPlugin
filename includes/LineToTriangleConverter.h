// LineToTriangleConverter.h
#pragma once

#include <vector>
#include <array>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <functional>

class LineToTriangleConverter {
public:
    using Vec3 = std::array<float, 3>;

    // 转换结果结构体
    struct MeshData {
        std::vector<float> vertices;    // 顶点位置 (x,y,z,x,y,z,...)
        std::vector<float> normals;     // 顶点法线 (nx,ny,nz,nx,ny,nz,...)
        std::vector<unsigned int> indices; // 三角形索引
    };

    // 将单条线段转换为圆柱体网格
    static MeshData convertLineToCylinder(
        const Vec3& p1,
        const Vec3& p2,
        float radius = 0.1f,
        int segments = 8);

    // 批量转换多条线段
    static MeshData convertLinesToCylinders(
        const std::vector<std::pair<Vec3, Vec3>>& lines,
        float radius = 0.1f,
        int segments = 8);

    static MeshData ConvertLineSegmentsToCylinders(
        const std::vector<float>& lineVertices,
        const std::vector<unsigned int>& lineIndices,
        float radius = 0.1f,
        int segments = 8);

private:
    static double NDS_PI;

    // 向量运算辅助函数
    static Vec3 subtract(const Vec3& a, const Vec3& b);
    static Vec3 add(const Vec3& a, const Vec3& b);
    static Vec3 multiply(const Vec3& v, float scalar);
    static Vec3 cross(const Vec3& a, const Vec3& b);
    static float length(const Vec3& v);
    static Vec3 normalize(const Vec3& v);

    // 计算面法线
    static Vec3 ComputeFaceNormal(const Vec3& v1, const Vec3& v2, const Vec3& v3);

    // 计算顶点法线（平均相邻面法线）
    static void ComputeVertexNormals(
        const std::vector<float>& vertices,
        const std::vector<unsigned int>& indices,
        std::vector<float>& normals);

    static void AddLineSegmentToMesh(
        const float* p1, const float* p2,
        float radius, int segments,
        std::vector<float>& outVertices,
        std::vector<unsigned int>& outIndices,
        unsigned int& vertexOffset);
};
