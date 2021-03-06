/* gencodeToGeneSymbol.c was originally generated by the autoSql program, which also 
 * generated gencodeToGeneSymbol.h and gencodeToGeneSymbol.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "gencodeToGeneSymbol.h"



char *gencodeToGeneSymbolCommaSepFieldNames = "transcriptId,symbol,geneId";

void gencodeToGeneSymbolStaticLoad(char **row, struct gencodeToGeneSymbol *ret)
/* Load a row from gencodeToGeneSymbol table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->transcriptId = row[0];
ret->symbol = row[1];
ret->geneId = row[2];
}

struct gencodeToGeneSymbol *gencodeToGeneSymbolLoad(char **row)
/* Load a gencodeToGeneSymbol from row fetched with select * from gencodeToGeneSymbol
 * from database.  Dispose of this with gencodeToGeneSymbolFree(). */
{
struct gencodeToGeneSymbol *ret;

AllocVar(ret);
ret->transcriptId = cloneString(row[0]);
ret->symbol = cloneString(row[1]);
ret->geneId = cloneString(row[2]);
return ret;
}

struct gencodeToGeneSymbol *gencodeToGeneSymbolLoadAll(char *fileName) 
/* Load all gencodeToGeneSymbol from a whitespace-separated file.
 * Dispose of this with gencodeToGeneSymbolFreeList(). */
{
struct gencodeToGeneSymbol *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[3];

while (lineFileRow(lf, row))
    {
    el = gencodeToGeneSymbolLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct gencodeToGeneSymbol *gencodeToGeneSymbolLoadAllByChar(char *fileName, char chopper) 
/* Load all gencodeToGeneSymbol from a chopper separated file.
 * Dispose of this with gencodeToGeneSymbolFreeList(). */
{
struct gencodeToGeneSymbol *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[3];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = gencodeToGeneSymbolLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct gencodeToGeneSymbol *gencodeToGeneSymbolCommaIn(char **pS, struct gencodeToGeneSymbol *ret)
/* Create a gencodeToGeneSymbol out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new gencodeToGeneSymbol */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->transcriptId = sqlStringComma(&s);
ret->symbol = sqlStringComma(&s);
ret->geneId = sqlStringComma(&s);
*pS = s;
return ret;
}

void gencodeToGeneSymbolFree(struct gencodeToGeneSymbol **pEl)
/* Free a single dynamically allocated gencodeToGeneSymbol such as created
 * with gencodeToGeneSymbolLoad(). */
{
struct gencodeToGeneSymbol *el;

if ((el = *pEl) == NULL) return;
freeMem(el->transcriptId);
freeMem(el->symbol);
freeMem(el->geneId);
freez(pEl);
}

void gencodeToGeneSymbolFreeList(struct gencodeToGeneSymbol **pList)
/* Free a list of dynamically allocated gencodeToGeneSymbol's */
{
struct gencodeToGeneSymbol *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    gencodeToGeneSymbolFree(&el);
    }
*pList = NULL;
}

void gencodeToGeneSymbolOutput(struct gencodeToGeneSymbol *el, FILE *f, char sep, char lastSep) 
/* Print out gencodeToGeneSymbol.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->transcriptId);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->symbol);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->geneId);
if (sep == ',') fputc('"',f);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */

