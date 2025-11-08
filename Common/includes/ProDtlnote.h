#ifndef PRODTLNOTE_H
#define PRODTLNOTE_H
			

#include <ProANSI.h>
#include <ProObjects.h> 
#include <ProDtlitem.h>
#include <ProDtlattach.h>
#include <ProDtlsymdef.h>
#include <ProDimension.h>
#include <ProGtol.h>
#include <ProNote.h>

typedef struct prodtl_text      *ProDtlnotetext;

typedef struct prodtl_text_line *ProDtlnoteline;

typedef struct pro_notedata     *ProDtlnotedata;

typedef enum horizontal_just
{
    PRO_HORZJUST_LEFT,
    PRO_HORZJUST_CENTER,
    PRO_HORZJUST_RIGHT,
    PRO_HORZJUST_DEFAULT  /* Indicates note with Creo Parametric default justification. */
}   ProHorizontalJustification;

typedef enum vertical_just
{
    PRO_VERTJUST_TOP,
    PRO_VERTJUST_MIDDLE,
    PRO_VERTJUST_BOTTOM,
    PRO_VERTJUST_DEFAULT  /* Indicates note with Creo Parametric default justification. */
} ProVerticalJustification;

PRO_BEGIN_C_DECLS
/*================================================================*\
    ProDtlnote  functions
\*=================================================================*/
extern ProError ProDrawingReadonlyselectionAllow(
    ProBoolean allow);
/*


  Purpose: Enables or disables the Creo Parametric user to select drawing 
           detail notes flagged as read-only.

  Input Arguments:

    allow       - Set to PRO_B_TRUE to enable selection, and PRO_B_FALSE
                  to disable it.

  Output Arguments:

    None

  Return Values:

    PRO_TK_NO_ERROR     - The function successfully set the flag.

*/

extern ProError ProDtlnoteCreate(ProMdl  owner,
                                 ProDtlsymdef *symbol,
                                 ProDtlnotedata notedata,
                                 ProDtlnote *note);
/*


  Purpose: Creates a note.

  Input Arguments:
    owner               - The owner handle.
    symbol              - If you are adding a note to the drawing, set the 
                          symbol to NULL. If you are adding a note to a
                          symbol definition, set the symbol to be that
                          symbol definition.
    notedata            - The note data.
  
  Output Arguments:

    note                - Created note.

  Return Values:

    PRO_TK_NO_ERROR      - The function successfully created the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The note could not be created.

*/

extern ProError ProDtlnoteDataGet(
    ProDtlnote *note,
    ProDtlsymdef *symbol,
    ProDisplayMode mode,
    ProDtlnotedata *notedata);
/*


  Purpose: Gets a note data for the specified note. The function allocates
           memory; user must release this memory with ProDtlnotedataFree

  Input Arguments:

    note                - The note.
    symbol              - If you are getting a note from the drawing, set the 
                          symbol to NULL. If you are getting a note from a
                          symbol definition, set the symbol to be that
                          symbol definition.
    mode                - The display mode. 
                          <p><b>Note:</b>Creo Parametric does not resolve and replace
                          symbolic callouts for notes, which are not displayed.
                          Therefore, for the value PRODISPMODE_NUMERIC, if the note is
                          not displayed or is hidden in a layer, the text retrieved may
                          contain the symbolic callouts. 
  
  Output Arguments:

    notedata            - The note data. Free the data using ProDtlnotedataFree.
  
  Return Values:

    PRO_TK_NO_ERROR      - The function successfully retrieved the note data.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.

*/

extern ProError ProDtlnoteDelete(
    ProDtlnote *note,
    ProDtlsymdef *symbol); 
/*


  Purpose: Deletes a note.

  Input Arguments:

    note                - The note.
    symbol              - If you are deleting a note from the drawing, set the 
                          symbol to NULL. If you are deleting a note from a
                          symbol definition, set the symbol to be that
                          symbol definition.
    
  Output Arguments:

    None
  
  Return Values:

    PRO_TK_NO_ERROR      - The function successfully deleted the note data.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The note could not be deleted.

*/

extern ProError ProDtlnoteModify(
    ProDtlnote *note,
    ProDtlsymdef *symbol,
    ProDtlnotedata notedata);
/*


  Purpose: Modifies a note.

  Input Arguments:

    note                - The note.
    symbol              - If you are modifying a note from the drawing, 
                          set the 
                          symbol to NULL. If you are modifying a note from a
                          symbol definition, set the symbol to be that
                          symbol definition.
    notedata            - The note data.

  Output Arguments:

    None
  
  Return Values:

    PRO_TK_NO_ERROR      - The function successfully modified the note data.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't modify the note.

*/

extern ProError ProDtlnoteDraw(
    ProDtlnote *note);
/*

Purpose: Draw a note. Make note in the database appear 
        on the drawing until the drawing is regenerated. 
	<B>NOTE: </B> The drawing must be current to use 
	this function
        

Input Arguments:

    note                - The note.
    

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully draw the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't draw the note.

*/ 

extern ProError ProDtlnoteErase(
    ProDtlnote *note);
/*

Purpose: Erase a note. Makes the note disappear 
        on the drawing until the drawing is regenerated. 
	<B>NOTE: </B> The drawing must be current to use 
	this function

Input Arguments:

    note                - The note.
    

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully erased the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't erase the note.

*/ 

extern ProError ProDtlnoteShow(
    ProDtlnote *note);
/*

Purpose: Show a note. Make note in the database appear 
        on the drawing and continue to appear after the 
	drawing is regenerated. 
        <B>NOTE: </B> The drawing must be current to use 
	this function; to set a note to be displayed in a non-current
	drawing using ProDtlnotedataDisplayedSet() and regenerate 
	the drawing. 

Input Arguments:

    note                 - The note.

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully show the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't show the note.

*/ 

extern ProError ProDtlnoteRemove(
    ProDtlnote *note);
/*

Purpose: Remove a note. Make note in the database 
        disappear on the drawing and continue to disappear after the 
        drawing is regenerated.  	
	<B>NOTE: </B> The drawing must be current to use 
	this function; to set a note to be undisplayed in a non-current
	drawing using ProDtlnotedataDisplayedSet() and regenerate 
	the drawing.

Input Arguments:

    note                 - The note.

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully removed the note.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - Can't remove the note.

*/ 

extern ProError ProDrawingDtlnotesCollect(
    ProDrawing drawing,
    ProDtlsymdef *symbol, 
    int sheet,
    ProDtlnote **notes); 
/*

Purpose: Collect notes in the specified drawing.

Input Arguments:

    drawing     - The drawing handle.
    symbol      - If you are collecting a note from the drawing, set the 
                  symbol to NULL. If you are collecting a note from a
                  symbol definition, set the symbol to be that
                  symbol definition.
    sheet       - The sheet number. Set to PRO_VALUE_UNUSED for current sheet.

Output Arguments:

    notes       - The ProArray of notes. The function  allocates memory for
                  array. User must release memory by ProArrayFree.
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully collected the notes.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_OUT_OF_MEMORY - The function found too many entities to be contained in the output ProArray.  Use ProDrawingDtlnoteVisit instead.
    PRO_TK_E_NOT_FOUND   - No notes were found.
    
*/ 

extern ProError ProDrawingDtlnoteVisit(
    ProDrawing drawing,
    ProDtlsymdef *symbol,
    int sheet,
    ProDtlitemVisitAction visit_action,
    ProDtlitemFilterAction filter_action,
    ProAppData appdata);
/*

Purpose: Visit notes in the specified drawing.

Input Arguments:

    drawing         - The drawing handle.
    symbol          - If you are visiting a note in the drawing, set the 
                      symbol to NULL. If you are visiting a note in a
                      symbol definition, set the symbol to be that
                      symbol definition.
    visit_action    - Visit action function.
    filter_action   - Filter action function. If NULL, all notes are  
                      visited using the action function. 
    sheet           - The sheet number.
    appdata         - The application data.

Output Arguments:

    None
        
Return Values:

    PRO_TK_NO_ERROR      - The function successfully visited the notes.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_GENERAL_ERROR - The function failed.
    PRO_TK_E_NOT_FOUND   - No notes were found.
    Other                - Return value passed by the caller's visit function.          
*/ 

extern ProError ProDtlnoteModelrefGet( ProDtlnote    *note,
                                       ProDtlsyminst *symbol_inst,
                                       int           line_index,
                                       int           text_index,
                                       ProMdl        *model );
/*
  Purpose:
  To provide the model to which parameterized text in a detail note refers.

  Input Arguments:
      note        - The note
      symbol_inst - Symbol instance whose definition contains the note.
                    Set to NULL if the note does not belong to a symbol.
      line_index  - The index into the note's line array of the line
                    containing the parameterized text.
      text_index  - The index into the line's text array of the text  item
                    containing the parameterized text.
 
  Output Arguments:
     model	  - The model which contains the parameters the
                    parameterized text refers to.

  Return Values:
       PRO_TK_NO_ERROR   - The function successfully found the model.
       PRO_TK_BAD_INPUTS - One or more arguments was invalid.
*/


extern ProError ProDtlnoteNoteGet (ProDtlnote *dtl_note, 
                                   ProNote*    solid_model_note);

/*
Purpose: Return the solid model note that shown as a detail note.

Input Arguments:
  dtl_note         - The drawing detail note that displays the model note.

Output Arguments:
  solid_model_note - The solid model note.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - The input argument is invalid.
  PRO_TK_NO_ACCESS   - Input note is not accessible.
  PRO_TK_E_NOT_FOUND - The detail note does not show a solid model note.
*/

extern ProError ProDtlnoteGtolGet (ProDtlnote *dtl_note , ProGtol *gtol);

/*
Purpose: Return the geometric tolerance shown in a detail note.

Input Arguments:
  dtl_note - The drawing detail note that displays the model note.

Output Arguments:
  gtol     - The geometric tolerance handle.

Return Values:
  PRO_TK_NO_ERROR    - The function successfully retrieved the note.
  PRO_TK_BAD_INPUTS  - One or more input arguments is invalid.
  PRO_TK_E_NOT_FOUND - The note is not showing a geometric tolerance.
*/


/*================================================================*\
    ProDtlnotedata  functions
\*=================================================================*/
extern ProError ProDtlnotedataAlloc(ProMdl owner,
                                    ProDtlnotedata *notedata);
/*

Purpose: Allocate and initialize memory for note data.
        User must release memory by ProDtlnotedataFree.

Input Arguments:
    owner           - The owner model of the note
    
Output Arguments:
    notedata        - The note data.
        
Return Values:
    PRO_TK_NO_ERROR         - The function successfully allocated memory.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
*/ 

extern ProError ProDtlnotedataFree(
    ProDtlnotedata notedata);
/*

Purpose: Release memory allocated by ProDtlnotedataAlloc.
        (Also frees text lines, texts and leaders)

Input Arguments:
    notedata                - The note data.
    
Output Arguments:

    None
        
Return Values:
    PRO_TK_NO_ERROR         - The function successfully release memory.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/

extern ProError ProDtlnotedataIdGet(
    ProDtlnotedata notedata,
    int *id);
/*

Purpose: Gets a note id.

Input Arguments:
    notedata                - The note data.
    
Output Arguments:
    id                      - The note id.
       
Return Values:
    PRO_TK_NO_ERROR      - The function successfully retrieved the note id.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataLineAdd(
    ProDtlnotedata notedata,
    ProDtlnoteline line);
/*

Purpose: Adds a text line to note.

Input Arguments:
    notedata                - The note data.
    line                    - The text line.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully added the text line.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnoteldataLinesSet(
    ProDtlnotedata notedata,
    ProDtlnoteline *line); 
/*

Purpose: Sets text lines to note.

Input Arguments:
    notedata                - The note data.
    line                    - ProArray of the text lines.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the text lines.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataLinesCollect(
    ProDtlnotedata notedata,
    ProDtlnoteline **lines);
/*

Purpose: Collect text lines in the specified note.

Input Arguments:
    notedata    - The note data.
    
Output Arguments:
    lines       - The ProArray of text lines. The function allocates memory for 
                  the array. User must release memory by ProArrayFree.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the text lines.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    PRO_TK_E_NOT_FOUND   - No text lines were found.
    
*/ 



       

extern ProError ProDtlnotedataAttachmentGet(
    ProDtlnotedata notedata,
    ProDtlattach *attachment);
/*

Purpose: Gets an attachment for the specified note.

Input Arguments:
    notedata                - The note data.
    
Output Arguments:
    attachment              - The note attachment. Release memory using 
                                ProDtlattachFree
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully retrieved the note
                                attachment.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataAttachmentSet(
    ProDtlnotedata notedata,
    ProDtlattach attachment);
/*

Purpose: Sets an attachment for the specified note.

Input Arguments:
    notedata                - The note data
    attachment              - The note color
    
Output Arguments:
    None 
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the note
                              attachment.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataLeadersCollect(
    ProDtlnotedata notedata,
    ProDtlattach **leaders); 
/*

Purpose: Collect leaders in the specified note.

Input Arguments:
    notedata        - The note data.
    
Output Arguments:
    leaders         - The ProArray of leaders. The function allocates memory 
                      for the array. User must release memory by ProArrayFree.
        
Return Values:
    PRO_TK_NO_ERROR      - The function successfully collected the leaders.
    PRO_TK_BAD_INPUTS    - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY - Not enough memory.
    PRO_TK_E_NOT_FOUND   - No leaders were found.
    
*/ 

extern ProError ProDtlnotedataLeadersSet(
    ProDtlnotedata notedata,
    ProDtlattach *leaders); 
/*

Purpose: Sets leaders for the note.

Input Arguments:
    notedata                - The note data.
    leaders                 - The ProArray of leaders.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the leaders.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataLeaderAdd(
    ProDtlnotedata data,
    ProDtlattach leader);
/*

Purpose: Adds a leader to the note.

Input Arguments:
    data                - The note data.
    leader              - The note leader.
    
Output Arguments:
    None
       
Return Values:
    PRO_TK_NO_ERROR         - The function successfully added the leader.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    PRO_TK_OUT_OF_MEMORY    - Not enough memory.
    
*/ 

extern ProError ProDtlnotedataElbowlengthGet(
    ProDtlnotedata  data,
    ProBoolean	*is_default,
    double *elbow_length);
/*

Purpose: Gets the elbow length for the specified note.

Input Arguments:
    data                - The note data.
    
Output Arguments:
    is_default          - The default flag. 
    elbow_length        - The note elbow length if is_default == PRO_B_FALSE.
     
Return Values:
    PRO_TK_NO_ERROR     - The function successfully retrieved the note
                          elbow.
    PRO_TK_BAD_INPUTS   - One or more arguments was invalid.
    
*/ 

extern ProError ProDtlnotedataElbowlengthSet(
    ProDtlnotedata data,
    ProBoolean	is_default,
    double elbow_length);
/*

Purpose: Sets the elbow length for the specified note.

Input Arguments:
    data                - The note data.
    is_default          - The default flag. 
    elbow_length        - The note elbow length if is_default == PRO_B_FALSE.
    
Output Arguments:
    None
     
Return Values:
    PRO_TK_NO_ERROR         - The function successfully set the note
                              elbow.
    PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
    
*/ 



/*================================================================*\
    ProDtlnotetext  functions
\*=================================================================*/
extern ProError ProDtlnotetextAlloc  (
    ProDtlnotetext *text );

/*  
    Purpose: 
	Allocate memory for the note text data.
	User must free memory with ProDtlnotetextFree().
	
    Input Arguments:
	None

    Output Arguments:
	text  - The note data handle

    Return Values:
	PRO_TK_NO_ERROR      - Success
	PRO_TK_OUT_OF_MEMORY - The function can't allocate memory
*/


extern ProError ProDtlnotetextFree(
    ProDtlnotetext text);

/*  
    Purpose: 
	Free memory that is allocated by ProDtlnotetextAlloc.
	
    Input Arguments:
        text  - The note data handle. 
         
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/




	



	


extern ProError ProDtlnotetextUlineSet (
    ProDtlnotetext text,
    ProBoolean underline);

/*  
    Purpose: 
	Setup the text underline attribute.
	
    Input Arguments:
	text         - The handle to the text
	underline    - The underline attribute.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextUlineGet (
    ProDtlnotetext text,
    ProBoolean *underline);

/*  
    Purpose: 
	Get the text underline attribute.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	underline    - The underline attribute.

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextStringSet (
    ProDtlnotetext text,
    ProLine string);

/*  
    Purpose: 
	Setup the string field in the text.
	
    Input Arguments:
	text         - The handle to the text
	string       - The content of the text part.
		       It can contain control characters
		       to introduce special symbols, as
		       described in the Drawing User's Guide.
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotetextStringGet (
    ProDtlnotetext text,
    ProLine string);

/* 
    Purpose: 
	Get the string field from the text.
	
    Input Arguments:
	text         - The handle to the text

    Output Arguments:
	string       - The content of the text part.
		       It can contain control characters
		       to introduce special symbols, as
		       described in the Drawing User's Guide.

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

/*================================================================*\
    ProDtlnoteline  functions
\*=================================================================*/
extern ProError ProDtlnotelineAlloc (
    ProDtlnoteline *line);

/* 
    Purpose: 
	Allocate memory for the note text line data.
	User must free memory by ProDtlnotelineFree()
	
    Input Arguments:
	None

    Output Arguments:
	line  - The note text line handle.  

    Return Values:
	PRO_TK_NO_ERROR      - Success;
	PRO_TK_OUT_OF_MEMORY - The  function can't allocate memory.
*/

extern ProError ProDtlnotelineFree (
    ProDtlnoteline line);

/*  
    Purpose: 
	Free memory that was allocated by ProDtlnotelineAlloc.
	
    Input Arguments:
        line  - The note text line handle.  
        
    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR   - success;
	PRO_TK_BAD_INPUTS - the argument is invalid.
*/

extern ProError ProDtlnotelineTextAdd (
    ProDtlnoteline line,
    ProDtlnotetext text);

/*  
    Purpose: 
	Add text to the note text line data.
	
    Input Arguments:
        line  - The note text line handle. 
	text  - The handle to the text.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
	PRO_TK_OUT_OF_MEMORY    - Not enough memory.
*/

extern ProError ProDtlnotelineTextsSet (
    ProDtlnoteline line,
    ProDtlnotetext *texts);

/*  
    Purpose: 
	Setup the text for the note text line data.
	
    Input Arguments:
	line    - The note text line handle. 
	texts   - A ProArray of of text handles.

    Output Arguments:
	None

    Return Values:
	PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
        PRO_TK_OUT_OF_MEMORY    - Not enough memory.
*/


extern ProError ProDtlnotelineTextsCollect (
    ProDtlnoteline line,
    ProDtlnotetext **text);

/*  
    Purpose:  Returns text entities contained in the note line. Each text 
              entity can have its own properties and parametric references.
       

    Input Arguments:

        line  - Line in note returned by function ProDtlnotedataLinesCollect().

    Output Arguments:

        text  - ProArray of text entities. Free the array memory with 
                ProArayFree(). 

    Return Values:
        PRO_TK_NO_ERROR         - Function completed successfully
        PRO_TK_BAD_INPUTS       - One or more bad arguments
        Pro_E_TK_NOT_FOUND      - No text entities in specified line
*/





extern ProError ProDtlnotedataReadonlySet(
    ProDtlnotedata notedata,
    ProBoolean read_only );

/*  
    Purpose:
        Sets read-only flag for the specified note.

    Input Arguments:
        notedata	- The note data.
	read_only	- PRO_B_TRUE to make note read-only, 
			  PRO_B_FALSE otherwise

    Output Arguments:
	None

    Return Values:
        PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
*/

extern ProError ProDtlnotedataReadonlyGet(
    ProDtlnotedata notedata,
    ProBoolean *read_only );

/*  
    Purpose:
        Gets read-only flag for the specified note.

    Input Arguments:
        notedata	- The note data.

    Output Arguments:
	read_only	- PRO_B_TRUE if note is read-only, 
			  PRO_B_FALSE otherwise

    Return Values:
        PRO_TK_NO_ERROR         - Success;
        PRO_TK_BAD_INPUTS       - One or more arguments was invalid.
*/

extern ProError ProDtlnoteLineEnvelopeGet(
    ProDtlnote *note,
    int line,
    ProVector envel[4]);

/*  
    Purpose:
        Get the envelope of a line in specified note.

    Input Arguments:
        note  	        - The note.
        line            - The line number, counting from 0.

    Output Arguments:
        envel           - The envelope, in screen coordinates.
                          The order of coordinates are as:<pre><br>
                          
                          0 -------- 1<br>
                          |          |<br>
                          2 -------- 3</pre>
                      
                          This ordering of points is preserved even if
                          the note is mirrored and/or at an angle.

    Return Values:
        PRO_TK_NO_ERROR   - Success.
        PRO_TK_BAD_INPUTS - One or more arguments was invalid.  
		PRO_TK_EMPTY      - The note is a blank string.  
*/

extern ProError ProDtlnotedataIsDisplayed(
    ProDtlnotedata data,
    ProBoolean *is_displayed);

/*
   Purpose:   Checks if the draft note is displayed.

   Input Arguments:
      data              - The draft note data.

   Output Arguments:
      is_displayed      - PRO_B_TRUE if the note is displayed by default.
                          PRO_B_FALSE if the note is hidden by default.

   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlnotedataDisplayedSet(
    ProDtlnotedata data,
    ProBoolean displayed);

/*
   Purpose:   Marks the draft entity to be displayed

   Input Arguments:
      data                 - The draft note data.
      displayed            - PRO_B_TRUE if the draft note should be displayed
                             after every regeneration.  PRO_B_FALSE 
			     if it should be undisplayed after every 
			     regeneration.

   Output Arguments:
      None


   Return Values:
      PRO_TK_NO_ERROR       - The function completed successfully.
      PRO_TK_BAD_INPUTS     - Invalid input argument(s).
*/

extern ProError ProDtlnoteDtlsyminstsCollect (
    ProDtlnote* note, 
    ProDtlsyminst** instances);
/*
   Purpose:   Returns a list of all symbol instances which are declared in a
              detail note via the "sym()" callout format.
              <P><B> Note: </B> The instances are returned in the order they are
              encountered in the note text.

   Input Arguments:
      note                 - The detail note.

   Output Arguments:
      instances            - ProArray of symbol instances. 
                             Free this using ProArrayFree().

   Return Values:
      PRO_TK_NO_ERROR      - The function succeeded.
      PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND   - There are no symbol instances generated as a
                             callout in this note.

*/


extern ProError  ProDtlnotetextStyleSet( ProDtlnotetext note_text,
                                         ProTextStyle r_text_style );

/*
  Purpose:
      Retrieves the text style of the specified text in the note

  Input Arguments:
     note_text    - The note text.
     r_text_style   - The text style of specified text in the note. 

  Output Arguments:
     none

  Return Values:

     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.  

*/

extern ProError  ProDtlnotetextStyleGet( ProDtlnotetext note_text,
                                         ProTextStyle *r_text_style );

/*
  Purpose:
      Retrieves the text style of the specified text in the note

  Input Arguments:
     note_text    - The note text.

  Output Arguments:
     r_text_style   - The text style of specified text in the note. Free this using ProTextStyleFree(). 


  Return Values:

     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.  

*/

extern ProError  ProDtlnotedataTextStyleSet(ProDtlnotedata  note_data,
                                            ProTextStyle r_text_style );

/*
  Purpose:
      Set text style in the note_data.

  Input Arguments:
     note_data    - The note data.
     r_text_style   - The text style of the note. 

  Output Arguments:

    None
        
  Return Values:

     PRO_TK_NO_ERROR   - The function succeeded.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.  

*/

extern ProError  ProDtlnotedataTextStyleGet (ProDtlnotedata note_data,
                                             ProTextStyle *r_text_style);

/*
  Purpose:
        Retrieves the text style of the note. If the note has texts with
        different styles, the returned style will have a mixed state for
        attributes that aren't the same in all texts. Inquiry functions
        such as ProTextStyleFontGet will return PRO_TK_GENERAL_ERROR when
        the attribute is in a mixed state.

  Input Arguments:
     note_data    - The note data.

  Output Arguments:
     r_text_style   - The text style of the note. Free this using ProTextStyleFree().

  Return Values:

     PRO_TK_NO_ERROR   - The function successfully retrieved the information.
     PRO_TK_BAD_INPUTS - One or more inputs are NULL or invalid.

*/


extern ProError ProTextStyleVertJustificationSet (ProTextStyle text_style,
                                         ProVerticalJustification justification);

/*
    Purpose: Assigns the vertical justification applied to the text style.

    Input Arguments:
        text_style - The text style.
        justification - The justification.

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProTextStyleVertJustificationGet (ProTextStyle text_style,
                                        ProVerticalJustification* justification);
/*
    Purpose: Obtains the vertical justification applied to the text style.

    Input Arguments:
        text_style - The text style.

    Output Arguments:
        justification - The justification.

    Return Values:
        PRO_TK_NO_ERROR   - The function succeeded.
        PRO_TK_E_NOT_FOUND - The input text style does not define
                             a vertical justification.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


extern ProError ProDtlnoteTableCellGet(ProDtlnote *note, ProDwgtable *table,
                                       int *p_row, int *p_col);
/*
   Purpose:   Returns information on the table, and row and column within
              that table, for a table note.

   Input Arguments:
      note                 - The detail note.

   Output Arguments:
      table                - The table (may be NULL).
      p_row                - The row, indexed starting at 0 (may be NULL).
      p_col                - The column, indexed starting at 0 (may be NULL).

   Return Values:
      PRO_TK_NO_ERROR      - The function succeeded, outputs 
      PRO_TK_BAD_INPUTS    - One or more input arguments was invalid.
      PRO_TK_E_NOT_FOUND   - This is not a table note.
*/

extern ProError ProDtlnoteWrapTextSet (ProDtlnote *note, ProBoolean wrap, double wrap_width);
/*
    Purpose: Sets wrap text ON or OFF

    Input Arguments:
        note - The note.
        wrap - PRO_B_TRUE to wrap the text.
                wrap_width - width of text line. if wrap is PRO_B_TRUE

    Output Arguments:
        none

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/

extern ProError ProDtlnoteWrapTextGet(ProDtlnote *note, ProBoolean *wrap, double* wrap_width);
/*
    Purpose: Get wrap status of the text

    Input Arguments:
        note - The note.

    Output Arguments:
        wrap - PRO_B_TRUE of wrap is set.
                wrap_width - width of wrapped text line.

    Return Values:
        PRO_TK_NO_ERROR - The function succeeded.
        PRO_TK_BAD_INPUTS - One or more input arguments was invalid.
*/


PRO_END_C_DECLS

#endif /* PRODTLNOTE_H */

