static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,69,66,80,66,66,73,76,106,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,89,51,51,52,90,72,
 85,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,71,80,65,32,32,32,32,32,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "gpa.sqc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"



/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 7 "gpa.sqc"
 


/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 9 "gpa.sqc"

   char db[6] = "cs348";
   char input[20], sname[20], term[10];
   float overall_gpa;
   float term_gpa;


/*
EXEC SQL END DECLARE SECTION;
*/

#line 15 "gpa.sqc"


int main(int argc, char *argv[]) {

    char output[100];

    
/*
EXEC SQL WHENEVER SQLERROR  GO TO error;
*/

#line 21 "gpa.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 23 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 23 "gpa.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 23 "gpa.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 23 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 23 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 23 "gpa.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 23 "gpa.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 23 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 23 "gpa.sqc"
  sqlastop(0L);
}

#line 23 "gpa.sqc"


    strncpy(input,argv[1],8);

    
/*
EXEC SQL SELECT s.sname INTO :sname
            FROM Student s
            WHERE s.snum = :input;
*/

{
#line 29 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 29 "gpa.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 29 "gpa.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 29 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 29 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 29 "gpa.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 29 "gpa.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 29 "gpa.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 29 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)sname;
#line 29 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 29 "gpa.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 29 "gpa.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 29 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 29 "gpa.sqc"
  sqlastop(0L);
}

#line 29 "gpa.sqc"
 

    
/*
EXEC SQL SELECT DISTINCT 1.0 * sum(m.grade) / count(e.cnum) INTO :overall_gpa
            FROM Mark m, Enrollment e
            WHERE e.snum = :input
                AND m.snum = e.snum;
*/

{
#line 34 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 34 "gpa.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 34 "gpa.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 34 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 34 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 34 "gpa.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 34 "gpa.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 34 "gpa.sqc"
      sql_setdlist[0].sqltype = 480; sql_setdlist[0].sqllen = 4;
#line 34 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)&overall_gpa;
#line 34 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 34 "gpa.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 34 "gpa.sqc"
  sqlacall((unsigned short)24,2,2,3,0L);
#line 34 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 34 "gpa.sqc"
  sqlastop(0L);
}

#line 34 "gpa.sqc"


    
/*
EXEC SQL DECLARE gpa CURSOR FOR 
            SELECT DISTINCT m.term, sum(m.grade) / count(e.cnum)
            FROM Mark m, Enrollment e
            WHERE e.snum = :input 
                AND m.snum = e.snum 
                AND m.cnum = e.cnum 
                AND m.term = e.term
            GROUP BY m.term
            ORDER BY m.term;
*/

#line 44 "gpa.sqc"

            
    
/*
EXEC SQL OPEN gpa;
*/

{
#line 46 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 46 "gpa.sqc"
  sqlaaloc(2,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 46 "gpa.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 46 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 46 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 46 "gpa.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 46 "gpa.sqc"
  sqlacall((unsigned short)26,3,2,0,0L);
#line 46 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 46 "gpa.sqc"
  sqlastop(0L);
}

#line 46 "gpa.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 47 "gpa.sqc"

    printf("GPA for student \"%s\"(%s) is %.1f. \n", sname, input, overall_gpa);
    for (;;) {
        
/*
EXEC SQL FETCH gpa INTO :term, :term_gpa;
*/

{
#line 50 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 50 "gpa.sqc"
  sqlaaloc(3,2,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 50 "gpa.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 50 "gpa.sqc"
      sql_setdlist[0].sqldata = (void*)term;
#line 50 "gpa.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 50 "gpa.sqc"
      sql_setdlist[1].sqltype = 480; sql_setdlist[1].sqllen = 4;
#line 50 "gpa.sqc"
      sql_setdlist[1].sqldata = (void*)&term_gpa;
#line 50 "gpa.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 50 "gpa.sqc"
      sqlasetdata(3,0,2,sql_setdlist,0L,0L);
    }
#line 50 "gpa.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 50 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 50 "gpa.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 50 "gpa.sqc"
  sqlastop(0L);
}

#line 50 "gpa.sqc"

        printf("%s %.1f \n", term, term_gpa);
    };    
    
end:
    
/*
EXEC SQL CLOSE gpa;
*/

{
#line 55 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 55 "gpa.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 55 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 55 "gpa.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 55 "gpa.sqc"
  sqlastop(0L);
}

#line 55 "gpa.sqc"

    
/*
EXEC SQL COMMIT;
*/

{
#line 56 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 56 "gpa.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 56 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 56 "gpa.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 56 "gpa.sqc"
  sqlastop(0L);
}

#line 56 "gpa.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 57 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 57 "gpa.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 57 "gpa.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 57 "gpa.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 57 "gpa.sqc"
  sqlastop(0L);
}

#line 57 "gpa.sqc"

    exit(0);

error:
    check_error("My error",&sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 62 "gpa.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 64 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 64 "gpa.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 64 "gpa.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 64 "gpa.sqc"
  sqlastop(0L);
}

#line 64 "gpa.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 65 "gpa.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 65 "gpa.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 65 "gpa.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 65 "gpa.sqc"
  sqlastop(0L);
}

#line 65 "gpa.sqc"

    exit(1);
}