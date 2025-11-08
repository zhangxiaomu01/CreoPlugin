#ifndef PROTBL_H
#define PROTBL_H 


#include <ProANSI.h>
#include <ProObjects.h>
#include <ProMdl.h>
#include <ProWstring.h>
#include <ProNote.h>

PRO_BEGIN_C_DECLS

/*typedef struct pro_draw_table *ProDwgtabledata;*/
typedef struct pro_table_data *ProTableData;

typedef enum
{
  PROTABLESIZE_CHARACTERS,
  PROTABLESIZE_MODEL_UNITS,/* For Drawing and Flat to Screen 
                              tables it is in screen unit*/
  PROTABLESIZE_CHARS_TRUE
} ProTableSizetype;


typedef enum
{
  PROTABLEFORMAT_TBL,
  PROTABLEFORMAT_TXT,
  PROTABLEFORMAT_CSV,
  PROTABLEFORMAT_XLSX
} ProTableFormattype;

typedef enum 
{
  PROTABLEGROWTHDIR_DOWNRIGHT = 0,
  PROTABLEGROWTHDIR_DOWNLEFT,
  PROTABLEGROWTHDIR_UPRIGHT,
  PROTABLEGROWTHDIR_UPLEFT
}ProTableGrowthdirType;

typedef enum
{
  PROTBLROWHEIGHT_AUTOADJUST_FALSE = 0,
  PROTBLROWHEIGHT_AUTOADJUST_TRUE,
  PROTBLROWHEIGHT_AUTOADJUST_TRUE_LEGACY
} ProTableRowheightAutoadjusttype;

typedef enum{
  PROTABLE_NORMAL  =  1,
  PROTABLE_FULL    =  2
} ProTableParamMode;

extern ProError ProTableDataAlloc(ProTableData *data);
/*  
    Purpose: Allocated memory for ProTableData structure.

    Input Arguments:
        None
    Output Arguments:
        data - pointer to the ProTableData structure
    
    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableDataOriginSet(ProTableData data,ProPoint3d origin);
/*
    Purpose:  Set the origin in the specified ProTableData structure

    Input Arguments:
        data - ProTableData structure
        origin - The origin for the table placement.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableDataFreeAttachSet(ProTableData data, ProAnnotationPlane* plane, ProPoint3d origin);
/*
    Purpose:  Set the free attachment in the specified ProTableData structure

    Input Arguments:
        data   - ProTableData structure
        plane  - Annotation Plane.
        origin - The origin for the table placement.
                 For tables on valid annotation plane pass this with respect to Model Csys.
                 For flat to screen tables pass this in 1000 x 843 fixed spaced

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableOriginGet(ProTable* table, int segment, ProPoint3d origin);
/*
    Purpose:  Get the origin in the specified ProTableData structure

    Input Arguments:
        table      - The table.
        segment    - The segment identifier.
                     Pass Segment Id for Drawing and 0 Model.

    Output Arguments:
        origin - The origin for the table placement.

    Return Values:
        PRO_TK_NO_ERROR      - Success
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableDataSizetypeSet(ProTableData  data, ProTableSizetype size_type);
/*  
    Purpose: Setup sizetype in the given ProTableData structure

    Input Arguments:
        data       -  ProTableData structure
        size_type  -  size type

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableDataColumnsSet (ProTableData data,int n_columns,double *widths,ProHorzJust *justifications);
/*  
    Purpose: Setup column properties

    Input Arguments:
        data           - The ProTableData structure
        n_columns      - Number of columns. The maximum number of
                         columns that can be specified is 50.
        widths         - ProArray of Column widths
        justifications - ProArray of Justifications

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_BAD_INPUTS    - Bad input argument 
*/

extern ProError ProTableDataRowsSet (ProTableData data,int n_rows,double *heights);
/*  
    Purpose: Setup rows properties

    Input Arguments:
        data          - The ProTableData structure
        n_rows        - Number of rows. The maximum number of
                        rows that can be specified is 100. 
        heights       - ProArray of row heights 

    Output Arguments:
        none

    Return Values:
    PRO_TK_NO_ERROR      - Success 
    PRO_TK_BAD_INPUTS    - Bad input argument 
*/

extern ProError ProTableDataAnnotationPlaneSet(ProTableData data, ProAnnotationPlane* plane);
/*
    Purpose: Set Annotation plane for solid tables.

    Input Arguments:
        data          - The ProTableData structure
        plane         - plane
     
    Output Arguments:
        none

    Return Values:
    PRO_TK_NO_ERROR      - Success
    PRO_TK_BAD_INPUTS    - Bad input argument
*/

extern ProError ProTableAnnotationPlaneGet(ProTable* table, ProAnnotationPlane* plane);
/*
    Purpose: Get Annotation plane for solid tables.

    Input Arguments:
        table      - The table.

    Output Arguments:
        plane         - plane

    Return Values:
    PRO_TK_NO_ERROR      - Success
    PRO_TK_BAD_INPUTS    - Bad input argument
*/

extern ProError ProTableCreate (ProMdl mdl, ProTableData table_data,int display,ProTable *table);
/*  
    Purpose: 
    Creates a table. The function creates the 
    table on the current sheet or active combination state.

    Input Arguments:
        mdl        - The Model
        table_data - The table data
        display    - Boolean flag that specifies whether or not the table is to
                     be displayed after creation. If display==FALSE, then the table is not
                     displayed.

    Output Arguments:
        table      - the table

    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableTextEnter(ProTable *table,int column,int row,ProWstring  *lines);
/* 
     Purpose: Adds the specified lines of text into the appropriate 
              column and row of the table. Note that more than one 
              line of text may be written into a cell. If a line of 
              text is too wide for the cell (too many characters), 
              the text overlaps the neighboring cells.

    Input Arguments:
        table   - The table to which to add the text for the cell.
        column  - The column number of the cell. The column
                  indices start at 1.
        row     - The row number of the cell. The row indices
                  start at 1.
        lines   - ProArray of text lines assigned to the table cell.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      - Success 
        PRO_TK_GENERAL_ERROR - Failure
*/

extern ProError ProTableDelete (ProTable *table);
/*  
    Purpose: Deletes the specified table.

    Input Arguments:
        table    - The table to delete.
        
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR  - The table was deleted.
        PRO_TK_NOT_EXIST - The specified <i>table_id</i> does not exist.
*/

extern ProError ProTableDisplay (ProTable *table, ProCombstate* state);
/*  
    Purpose: Displays the table.

    Input Arguments:
        table    - The table to display.
        state    - The combination state to display to. Pass NULL for drawing table.
       
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      - The table was deleted.
        PRO_TK_BAD_INPUTS    - The specified table was NULL.
        PRO_TK_GENERAL_ERROR - The function failed.
*/

extern ProError ProTableErase (ProTable *table, ProCombstate* state);
/*  
    Purpose: Erases the table.

    Input Arguments:
        table    - The table to erase.
        state    - The combination state to erase from. Pass NULL for drawing table.
       
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      - The table was deleted.
        PRO_TK_BAD_INPUTS    - The specified table was NULL.
        PRO_TK_GENERAL_ERROR - The function failed.
*/

typedef ProError (*ProTableVisitAction) (ProTable *table, ProError filter_status, ProAppData  data);
/*
    Purpose: The action function called for each drawing table entity during 
       the call to ProTableVisit().

    Input Arguments:
       table         -  Table to be visited
       filter_status -  Return value from filter action function
       data          -  Application data passed to function 
                        ProTableVisit().
        
    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR - Continue visiting drawing tables.
        Other           - Stop visiting tables.

*/

typedef ProError (*ProTableFilterAction) (ProTable *table, ProAppData  data);
/*

    Purpose: The filter function called for each  table entity during the 
         call to function ProTableVisit().

    Input Arguments:
        table      -  Table to be filtered
        data       -  Application data passed to function 
                      ProTableVisit().
        
    Output Arguments:
        None

    Return Values:
        PRO_TK_CONTINUE - Skip visiting this drawing table and go to the next.
        Other           - Call the visit action for this drawing table. The 
                          return value is passed as input to the visit action.

*/

extern ProError ProTableVisit (ProMdl model,ProTableVisitAction visit_action,ProTableFilterAction filter_action,ProAppData data);
/*
    Purpose: Visit tables in the specified model.

    Input Arguments:
    model       - model to visit
    visit_action  - visit action 
    filter_action - filter action. If NULL, 
                    all tables are visited 
                        using the action function.
    data          - ProAppData structure

    Output Arguments:
    none

    Return Values:
    PRO_TK_NO_ERROR      - The function successfully visited the tables.
    PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
    PRO_TK_E_NOT_FOUND   - No tables were visited.
    Other                - Error return supplied by the visit action which
                           caused visiting to stop.
*/

extern ProError ProTablesCollect (ProMdl  model,ProTable **tables);
/*  
    Purpose: Collect all tables in the specified model

    Input Arguments:
        model - the model

    Output Arguments:
        tables   - the array of table. The function 
                   allocates the memory for this argument. 
                To free the memory, call <b>ProArrayFree()</b>.

    Return Values:
        PRO_TK_NO_ERROR      - The function successfully collected the tables.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_E_NOT_FOUND   - No tables were found.
*/

extern ProError ProTableRowsColumnsCount(ProTable *table,int *n_rows, int *n_columns);
/*   
    Purpose: Counts the table rows and columns.

    Input Arguments:
        table - The table

    Output Arguments:
        n_rows    - rows count.
        n_columns - columns count

    Return Values:
        PRO_TK_NO_ERROR  - Success  .
        PRO_TK_NOT_EXIST - The specified table or drawing does not exist.
*/

extern ProError ProTableRowAdd (ProTable *table,int insert_after_row,int display, double height_in_chars);
/*   
     Purpose: Adds a row to a table.
    If you try to insert a row in the middle of a 
    nontemplate element of a repeat region,
    this function returns an error.

    Input Arguments:
    table            - the table;
    insert_after_row - Insert the new row after this row. Row numbers start with 1.
                       Pass the value 0 to insert the new row at the top of the table
                       To Append at last pass value less that 0.(any negative Value)
    display          - Flag that specifies whether or not the table is to be
               displayed after creation.
    height_in_chars  - The height of the row in characters.
                       Pass -1 to take value of previous column and first column in case of add at start.


    Output Arguments:
    None

    Return Values:
    PRO_TK_NO_ERROR      - Success.
    PRO_TK_GENERAL_ERROR - Failure 
*/

extern ProError ProTableColumnAdd (ProTable *table,int insert_after_col,int display, double width_in_chars);
/*   
     Purpose: Adds column to a table

     Input Arguments:
        table	         - the table;
        insert_after_col - insert the new column after this column. Column numbers start with 1.
                           If you want the new column to be the first column, pass the value 0.
                           To Append at last pass value less that 0.(any negative Value)
    display          - Flag that specifies whether or not the table is to
               be displayed after creation.
        width_in_chars   - The width of the column, in characters.
                           Pass -1 to take value of previous column and first column in case of add at start.
    
     Output Arguments:
    None

    Return Values:
    PRO_TK_NO_ERROR      - Success.
    PRO_TK_GENERAL_ERROR - Failure 
*/

extern ProError ProTableCellsMerge (ProTable *table,
                                    int       start_column,
                                    int       start_row,
                                    int       end_column,
                                    int       end_row,
                                    int       display);
/*   
    Purpose: Takes a rectangular region of cells and merges them
    into a composite cell. The merged cells, rows, or 
    columns are deleted, and the table's appearance will be 
    restored using prodrw_remesh_table_cells(). This
    function is equivalent to the Creo Parametric option
    Drawing, Table, Mod Rows/Col, Merge.
    Restrictions placed in the user interface also apply 
    here. For example, borders of merge cannot intersect 
    the borders of another merge or repeat region.

    Input Arguments:
    table        - The table
    start_column - The leftmost column of the merged cell
    start_row    - The upper row of the merged cell
    end_column   - The rightmost column of the merged cell
    end_row      - The bottom row of the merged cell
    display          - Flag that specifies whether or not the table is to be
               displayed after creation.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR      - Success;
    PRO_TK_GENERAL_ERROR - Failure.
		PRO_TK_NOT_VALID     - When the input row or the column does not exist.
*/

extern ProError ProTableCellsRemesh(ProTable* table, 
                                    int       start_column, 
                                    int       start_row, 
                                    int       end_column, 
                                    int       end_row, 
                                    int       display);
/*  
    Purpose: Undoes all merges created in the specified rectangular region.

    Input Arguments:
    table        - the table;
    start_column - the leftmost column of the region to remesh;
    start_row    - the upper row of the region to remesh;
    end_column   - the rightmost column of the region to remesh; 
    end_row      - the bottom row of the region to remesh.
    display      - Flag that specifies whether or not the table is to be
                       displayed after creation.  If display==TRUE, then the 
                       table is displayed (behavior as in releases prior to
                       Release 20). If display==FALSE, then the table is not
                       displayed.

    Output Arguments:
        None

    Return Values:
         PRO_TK_NO_ERROR      - Success.
     PRO_TK_GENERAL_ERROR - Failure.
         PRO_TK_NOT_VALID     - When the input row or the column does not exist.
*/

extern ProError ProTableRowDelete (ProTable *table, int row, int display);
/*  
    Purpose: Delete the specified row from the table.

    Input Arguments:
        table   - The table;
        row     - The row index.
              Row indices start at 1.
        display - Flag that specifies whether or not the table is to be
              displayed after creation.

    Output Arguments:
        None

    Return Values:
        PRO_TK_NO_ERROR      - Success;
        PRO_TK_GENERAL_ERROR - Failure.
*/
/*ProDwgtableColumnDelete*/
extern ProError ProTableColumnDelete (ProTable *table, int column, int display);
/*   
     Purpose: Deletes the specified column from the table.

    Input Arguments:
    table   - The table.
    column  - The column index. The indices start at 1.
    display - Flag that specifies whether or not the table is to be
                  displayed after creation.  If display==TRUE, then the 
                  table is displayed (behavior as in releases prior to Release 
                  20). If display==FALSE, then the table is not displayed.

    Output Arguments:
        None

    Return Values:
         PRO_TK_NO_ERROR      - Success;
     PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProTableCellNoteGet(ProTable* table, int column, int row, int* id);
/*
     Purpose: Returns the note identifier for a specified cell of the table.

    Input Arguments:
        table  - the reference to the table.
        column - The column index. Column indices start at 1.
        row    - The row index. Row indices start at 1.

    Output Arguments:
        id     - The id of note for the specified cell.

    Return Values:
        PRO_TK_NO_ERROR      - The note identifier for the specified cell.
        PRO_TK_EMPTY         - The cell is empty.
        PRO_TK_GENERAL_ERROR - Another error occurred and the function failed.
*/

extern ProError ProTableCelltextGet(ProTable* table, int column, int row, ProTableParamMode mode,ProWstring **lines);
/*  
    Purpose:Places the text of the table into a string array.

    Input Arguments:
        table  - The table.
        row    - The row index. The row indices start at 1.
        column - The column index. The column indices start at 1.
        mode   - The mode type. Use 1 to get the text as displayed.
                 Use 2 to get the text as shown in the full note
                 editor, in n:&symbol notation.

    Output Arguments:
        lines   - The text of the table. Free this using
                      ProWstringproarrayFree().

    Return Values:
    PRO_TK_NO_ERROR        - Success
    PRO_TK_GENERAL_ERROR   - Failure or table cell does not have any
                                 entered text 
*/

extern ProError ProTableRotate (ProTable *table,int display);
/*   
     Purpose: Rotates table (counter clockwise) by 90 degree.The function does not perform a display.

    Input Arguments:
    table    - The table.
    display  - Flag that specifies whether or not the table is to be
           displayed after creation.

    Output Arguments:
        none

    Return Values:
         PRO_TK_NO_ERROR      - Success;
     PRO_TK_GENERAL_ERROR - Failure.
*/

extern ProError ProTableCellIsComment (ProTable *table,int column,int row,ProBoolean  *is_comment);
/*  
    Purpose: Determines whether the specified cell 	is a comment cell.

    Input Arguments:
        table  - the table;
        column - the column index. The column indices start at 1.
        row    - the row index.  The row indices start at 1.

    Output Arguments:
        is_comment - PRO_B_TRUE if the cell is a comment cell.  PRO_B_FALSE otherwise.

    Return Values:
        PRO_TK_NO_ERROR   - success.
                PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProTableIsFromFormat (ProTable *table,ProBoolean  *from_format);
/*  
    Purpose: Determines whether the specified table is associated with the format.
             This API is for drawing table only.

    Input Arguments:
        table - The drawing table

    Output Arguments:
        from_format - PRO_B_TRUE if the table is associated with the format;
                  PRO_B_FALSE if the table is not associated with the format.
    Return Values: 
        PRO_TK_NO_ERROR	     - The function succeeded.
        PRO_TK_GENERAL_ERROR - The function failed. 	
*/

extern ProError ProTableColumnWidthSet(ProTable* table,int column,double column_width,ProTableSizetype size_type);
/*
    Purpose: Set the column width of a table.

    Input Arguments:
        table - The reference to the table.
        column - The column index. Column indices start at 1.
        column_width - Column width
        size_type    - Size type.If PROTABLESIZE_CHARACTERS,then
                       column_width will be rounded down.
                       To avoid this, use PROTABLESIZE_CHARS_TRUE.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The column width could not set
*/

extern ProError ProTableColumnWidthGet(ProTable* table,int column, ProTableSizetype size_type,double* column_width);
/*
    Purpose: Get the column width of a table.

    Input Arguments:
        table      - The reference to the table.
        column     - The column index. Column indices start at 1.
        size_type  - Size type.If PROTABLESIZE_CHARACTERS,then
                     column_width will be rounded down.
                     To avoid this, use PROTABLESIZE_CHARS_TRUE.

    Output Arguments:
        column_width - Column width

    Return Values:
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The column width could not get
*/

extern ProError ProTableRowHeightSet(ProTable*        table,
                                     int              row,
                                     double           row_height,
                                     ProTableSizetype size_type);
/*
    Purpose: Set the row height of a table

    Input Arguments:
        table      - The reference to the table.
        row - The row index
        row_height - Row height
        size_type  - Size type. If PROTABLESIZE_CHARACTERS,
                     then row_height will be rounded down.
                     To avoid this, use PROTABLESIZE_CHARS_TRUE.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The row height could not set
*/

extern ProError ProTableRowHeightGet(ProTable*        table, 
                                     int              row, 
                                     ProTableSizetype size_type, 
                                     double*          row_height);
/*
    Purpose: Get the row height of a table

  Input Arguments:
        table - The reference to the table.
        row        - The row index
        size_type  - Size type. If PROTABLESIZE_CHARACTERS,
                     then row_height will be rounded down.
                     To avoid this, use PROTABLESIZE_CHARS_TRUE.

  Output Arguments:
        row_height - Row height

  Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The row height could not set
*/

extern ProError ProTableRowheightAutoadjustSet(ProTable*                       table,
                                               int                             row,
                                               ProTableRowheightAutoadjusttype auto_adjust);
/*
    Purpose: Set the automatic row height adjustment property for a row of a table.

    <P><B>NOTE: </B>Height changes (if any) will be visible only after next regeneration 
                or a call to ProTablesUpdate()

  Input Arguments:
        table       - The reference to the table.
        row         - Row number for which the property is to be set.
                      Row numbers start with 1.
        auto_adjust - PROTBLROWHEIGHT_AUTOADJUST_TRUE to set the property,
                      PROTBLROWHEIGHT_AUTOADJUST_FALSE to unset it.

  Output Arguments:
      none

  Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The automatic adjust property could not be set.
        PRO_TK_CANT_MODIFY - The row is a non-template repeat region row.
*/

extern ProError ProTableRowheightAutoadjustGet(ProTable*                        table,
                                               int                              row,
                                               ProTableSizetype                 size_type, 
                                               ProTableRowheightAutoadjusttype* auto_adjust,
                                               double*                          height);
/*
  Purpose: Get the automatic row height adjustment property for a row of a table.

  Input Arguments:
        table     - The reference to the table.
        row       - Row number for which the property is to be retrieved.
                    Row numbers start with 1.
        size_type - Size type. If PROTABLESIZE_CHARACTERS,
                    then row_height will be rounded down.
                    To avoid this, use PROTABLESIZE_CHARS_TRUE.

  Output Arguments:
        auto_adjust - Retrieved value for auto-adjust property.
        height      - Auto adjusted height if auto_adjust is 
                      PROTBLROWHEIGHT_AUTOADJUST_TRUE.
                      Ignore for PROTBLROWHEIGHT_AUTOADJUST_FALSE

  Return Values:
        PRO_TK_NO_ERROR      - The function succeeded.
        PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The automatic adjust property could not be retrieved.
*/

extern ProError ProTableReferencesAdd(ProTable* table, ProAnnotationReference* refs);
/*
    Purpose: Add table references

    Input Arguments:
        table - Valid table.
        refs  - ProArray of table references.
                Only 1 reference from type PRO_ANNOT_REF_SRF_COLLECTION is allowed.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR          - The function completed successfully.
        PRO_TK_BAD_INPUTS        - The input argument is invalid.
        PRO_TK_BAD_CONTEXT       - The table owner is drawing.
        PRO_TK_MAX_LIMIT_REACHED - More than 1 references from type PRO_ANNOT_REF_SRF_COLLECTION.
        PRO_TK_CANT_MODIFY       - Refercnce from type PRO_ANNOT_REF_SRF_COLLECTION already exist.

*/

extern ProError ProTableReferencesGet(ProTable* table, ProAnnotationReference** p_refs);
/*
    Purpose: Get table references

  Input Arguments:
        table    - Valid table.

  Output Arguments:
        p_refs   - ProArray of table references. Free it using ProAnnotationreferencearrayFree()

  Return Values:
        PRO_TK_NO_ERROR       - The function completed successfully.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
        PRO_TK_BAD_CONTEXT    - The table owner is drawing.
*/

extern ProError ProTableReferenceDelete(ProTable* table, int index_ref);
/*
    Purpose: Delete table reference

    Input Arguments:
        table      - Valid table.
        index_ref  - Indices start from 0. Get existing references from ProTableReferencesGet()

    Output Arguments:

    Return Values:
        PRO_TK_NO_ERROR       - The function completed successfully.
        PRO_TK_BAD_INPUTS     - The input argument is invalid.
        PRO_TK_BAD_CONTEXT    - The table owner is drawing..
*/

extern ProError ProTableSave(ProTable* table, ProPath path, ProTableFormattype table_format, int segment_id);
/*
    Purpose: Save table in different format

    Input Arguments:
        table        - The reference to the table.
        path         - Full path of the saved location
        table_format - Save format of the table
        segment_id   - segment of the table to save, if table_format is
                       PROTABLEFORMAT_CSV or PROTABLEFORMAT_XLSX

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
        PRO_TK_GENERAL_ERROR - The function failed

*/

extern ProError ProSelectionTableGet(ProSelection selection, ProTable* table);
/*
   Purpose: For a ProSelection representing a cell of a table,
            returns the table from which the cell was selected.

   Input Arguments:
       selection - ProSelection representing a cell of a table.

   Output Arguments:
         table - The table from which the cell was selected.


   Return Values:
      PRO_TK_BAD_INPUTS - selection not provided, selection not a table cell,
                          or ProTable for output not provided.
      PRO_TK_NO_ERROR    - Successfully found table corresponding to the table cell.

*/

PRO_END_C_DECLS

#endif /* PROTBL_H */
    

