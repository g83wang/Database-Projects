static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,111,65,49,66,65,73,76,106,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,89,51,51,52,90,72,
 85,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,67,79,78,70,76,73,67,84,0,0,0,0,0,0,0,0,
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


#line 1 "conflicts.sqc"
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


#line 7 "conflicts.sqc"
 


/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 9 "conflicts.sqc"

   char db[6] = "cs348";
   char input[20];
   char sname[100], pname[100];
   char day[20], time[20];
   char cnum1[10], room1[10];
   char cnum2[10], room2[10];
   short section1;
   short section2;


/*
EXEC SQL END DECLARE SECTION;
*/

#line 19 "conflicts.sqc"


int main(int argc, char *argv[]) {

    char output[100];

    
/*
EXEC SQL WHENEVER SQLERROR  GO TO error;
*/

#line 25 "conflicts.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 27 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 27 "conflicts.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 27 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 27 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 27 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 27 "conflicts.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 27 "conflicts.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 27 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 27 "conflicts.sqc"
  sqlastop(0L);
}

#line 27 "conflicts.sqc"


    printf("Connected to CS348\n");

    printf("Input Number: %s \n", argv[1]);

    strncpy(input,argv[1],8);

    
/*
EXEC SQL SELECT s.sname INTO :sname
            FROM Student s
            WHERE s.snum = :input;
*/

{
#line 37 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 37 "conflicts.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 37 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 37 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 37 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 37 "conflicts.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 37 "conflicts.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 37 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 100;
#line 37 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)sname;
#line 37 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 37 "conflicts.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 37 "conflicts.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 37 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 37 "conflicts.sqc"
  sqlastop(0L);
}

#line 37 "conflicts.sqc"
 

    
/*
EXEC SQL SELECT p.pname INTO :pname
            FROM Professor p
            WHERE p.pnum = :input;
*/

{
#line 41 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 41 "conflicts.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 41 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 41 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 41 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 41 "conflicts.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 41 "conflicts.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 41 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 100;
#line 41 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)pname;
#line 41 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 41 "conflicts.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 41 "conflicts.sqc"
  sqlacall((unsigned short)24,2,2,3,0L);
#line 41 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 41 "conflicts.sqc"
  sqlastop(0L);
}

#line 41 "conflicts.sqc"
 

    
/*
EXEC SQL DECLARE conflict CURSOR FOR 
            SELECT DISTINCT se1.day, se1.time, se1.cnum, se1.section, se1.room, se2.cnum, se2.section, se2.room  
            FROM Schedule se1, Enrollment e1, Schedule se2, Enrollment e2
            WHERE e1.snum = :input AND e2.snum = :input
                AND e1.term = se1.term AND e2.term = se2.term
                AND e1.section = se1.section AND e2.section = se2.section
                AND e1.cnum = se1.cnum AND e2.cnum = se2.cnum
                AND e1.term = e2.term AND se1.day = se2.day AND se1.time = se2.time AND se1.cnum <> se2.cnum
                AND NOT EXISTS (
                    SELECT *
                    FROM Mark m
                    WHERE (m.term = e1.term AND m.cnum = e1.cnum AND m.section = e1.section) OR
                          (m.term = e2.term AND m.cnum = e2.cnum AND m.section = e2.section)
                );
*/

#line 56 "conflicts.sqc"

            
    
/*
EXEC SQL OPEN conflict;
*/

{
#line 58 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 58 "conflicts.sqc"
  sqlaaloc(2,2,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 58 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 58 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 58 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 58 "conflicts.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 20;
#line 58 "conflicts.sqc"
      sql_setdlist[1].sqldata = (void*)input;
#line 58 "conflicts.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 58 "conflicts.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 58 "conflicts.sqc"
  sqlacall((unsigned short)26,3,2,0,0L);
#line 58 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 58 "conflicts.sqc"
  sqlastop(0L);
}

#line 58 "conflicts.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 59 "conflicts.sqc"


    for (;;) {
        
/*
EXEC SQL FETCH conflict INTO :day, :time, :cnum1, :section1, :room1, :cnum2, :section2, :room2;
*/

{
#line 62 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 62 "conflicts.sqc"
  sqlaaloc(3,8,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[8];
#line 62 "conflicts.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 20;
#line 62 "conflicts.sqc"
      sql_setdlist[0].sqldata = (void*)day;
#line 62 "conflicts.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 20;
#line 62 "conflicts.sqc"
      sql_setdlist[1].sqldata = (void*)time;
#line 62 "conflicts.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 10;
#line 62 "conflicts.sqc"
      sql_setdlist[2].sqldata = (void*)cnum1;
#line 62 "conflicts.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[3].sqltype = 500; sql_setdlist[3].sqllen = 2;
#line 62 "conflicts.sqc"
      sql_setdlist[3].sqldata = (void*)&section1;
#line 62 "conflicts.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[4].sqltype = 460; sql_setdlist[4].sqllen = 10;
#line 62 "conflicts.sqc"
      sql_setdlist[4].sqldata = (void*)room1;
#line 62 "conflicts.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[5].sqltype = 460; sql_setdlist[5].sqllen = 10;
#line 62 "conflicts.sqc"
      sql_setdlist[5].sqldata = (void*)cnum2;
#line 62 "conflicts.sqc"
      sql_setdlist[5].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[6].sqltype = 500; sql_setdlist[6].sqllen = 2;
#line 62 "conflicts.sqc"
      sql_setdlist[6].sqldata = (void*)&section2;
#line 62 "conflicts.sqc"
      sql_setdlist[6].sqlind = 0L;
#line 62 "conflicts.sqc"
      sql_setdlist[7].sqltype = 460; sql_setdlist[7].sqllen = 10;
#line 62 "conflicts.sqc"
      sql_setdlist[7].sqldata = (void*)room2;
#line 62 "conflicts.sqc"
      sql_setdlist[7].sqlind = 0L;
#line 62 "conflicts.sqc"
      sqlasetdata(3,0,8,sql_setdlist,0L,0L);
    }
#line 62 "conflicts.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 62 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 62 "conflicts.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 62 "conflicts.sqc"
  sqlastop(0L);
}

#line 62 "conflicts.sqc"

        printf("%s %s: %s(%d) %s -- %s(%d) %s\n", day, time, cnum1, section1, room1, cnum2, section2, room2);
    };    
    
end:
    
/*
EXEC SQL CLOSE conflict;
*/

{
#line 67 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 67 "conflicts.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 67 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 67 "conflicts.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 67 "conflicts.sqc"
  sqlastop(0L);
}

#line 67 "conflicts.sqc"

    
/*
EXEC SQL COMMIT;
*/

{
#line 68 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 68 "conflicts.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 68 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 68 "conflicts.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 68 "conflicts.sqc"
  sqlastop(0L);
}

#line 68 "conflicts.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 69 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 69 "conflicts.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 69 "conflicts.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 69 "conflicts.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 69 "conflicts.sqc"
  sqlastop(0L);
}

#line 69 "conflicts.sqc"

    exit(0);

error:
    check_error("My error",&sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 74 "conflicts.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 76 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 76 "conflicts.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 76 "conflicts.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 76 "conflicts.sqc"
  sqlastop(0L);
}

#line 76 "conflicts.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 77 "conflicts.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 77 "conflicts.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 77 "conflicts.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 77 "conflicts.sqc"
  sqlastop(0L);
}

#line 77 "conflicts.sqc"

    exit(1);
}