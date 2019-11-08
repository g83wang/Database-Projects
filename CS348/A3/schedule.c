static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,66,65,109,106,86,72,76,106,48,49,49,49,
 49,32,50,32,32,32,32,32,32,32,32,32,8,0,89,51,51,52,90,72,
 85,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,8,0,83,67,72,69,68,85,76,69,0,0,0,0,0,0,0,0,
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


#line 1 "schedule.sqc"
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


#line 7 "schedule.sqc"
 


/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 9 "schedule.sqc"

   char db[6] = "cs348";
   char sname[70], cname[70], cnum[7], day[20], time[10], room[7], snum[8], term[10];
   short section;


/*
EXEC SQL END DECLARE SECTION;
*/

#line 14 "schedule.sqc"


int main(int argc, char *argv[]) {

    char output[100];

    
/*
EXEC SQL WHENEVER SQLERROR  GO TO error;
*/

#line 20 "schedule.sqc"


    
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 22 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 22 "schedule.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 22 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 6;
#line 22 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 22 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 22 "schedule.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 22 "schedule.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 22 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 22 "schedule.sqc"
  sqlastop(0L);
}

#line 22 "schedule.sqc"


    printf("Connected to CS348\n");

    printf("Student Number: %s \n", argv[1]);

    strncpy(snum,argv[1],8);

    
/*
EXEC SQL SELECT s.sname INTO :sname
            FROM Student s
            WHERE s.snum = :snum;
*/

{
#line 32 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 32 "schedule.sqc"
  sqlaaloc(2,1,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 32 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 8;
#line 32 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)snum;
#line 32 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 32 "schedule.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 32 "schedule.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 32 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 70;
#line 32 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)sname;
#line 32 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 32 "schedule.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 32 "schedule.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 32 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 32 "schedule.sqc"
  sqlastop(0L);
}

#line 32 "schedule.sqc"
 



    
/*
EXEC SQL GOTO nodata;
*/

/*
SQL0104N  An unexpected token "END-OF-STATEMENT" was found 
following "GOTO nodata".  Expected tokens may include:  
"JOIN <joined_table>".  SQLSTATE=42601

*/



    
/*
EXEC SQL SELECT DISTINCT e.term INTO :term
            FROM Enrollment e
            WHERE not exists(
                SELECT *
                FROM Mark m
                WHERE m.cnum = e.cnum
                    AND m.term = e.term
                    AND m.section = e.section 
                );
*/

{
#line 47 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 47 "schedule.sqc"
  sqlaaloc(3,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 47 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 47 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)term;
#line 47 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 47 "schedule.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 47 "schedule.sqc"
  sqlacall((unsigned short)24,2,0,3,0L);
#line 47 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 47 "schedule.sqc"
  sqlastop(0L);
}

#line 47 "schedule.sqc"
  

    
/*
EXEC SQL DECLARE schedule CURSOR FOR 
             SELECT c.cname, c.cnum, se.day, se.section, se.time, se.room, s.sname 
             FROM Student s, Schedule se, Enrollment e, Course c
             WHERE s.snum = :snum
               AND e.snum = s.snum
               AND se.cnum = e.cnum
               AND c.cnum = e.cnum
               AND not exists (
                   SELECT *
                   FROM Mark m
                   WHERE m.term = e.term
                        AND m.cnum = e.cnum  
                        AND m.section = e.section
               )
               ORDER BY se.day;
*/

#line 63 "schedule.sqc"


    
/*
EXEC SQL OPEN schedule;
*/

{
#line 65 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 65 "schedule.sqc"
  sqlaaloc(2,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 65 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 8;
#line 65 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)snum;
#line 65 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 65 "schedule.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 65 "schedule.sqc"
  sqlacall((unsigned short)26,3,2,0,0L);
#line 65 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 65 "schedule.sqc"
  sqlastop(0L);
}

#line 65 "schedule.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 66 "schedule.sqc"

    printf("Schedule for %s (%s) and term<%s>\n", sname, snum, term);
    printf("-------\n");
    for (;;) {
        
/*
EXEC SQL FETCH schedule INTO :cname, :cnum, :day, :section, :time, :room, :sname;
*/

{
#line 70 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 70 "schedule.sqc"
  sqlaaloc(3,7,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[7];
#line 70 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 70;
#line 70 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)cname;
#line 70 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 70 "schedule.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 7;
#line 70 "schedule.sqc"
      sql_setdlist[1].sqldata = (void*)cnum;
#line 70 "schedule.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 70 "schedule.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 20;
#line 70 "schedule.sqc"
      sql_setdlist[2].sqldata = (void*)day;
#line 70 "schedule.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 70 "schedule.sqc"
      sql_setdlist[3].sqltype = 500; sql_setdlist[3].sqllen = 2;
#line 70 "schedule.sqc"
      sql_setdlist[3].sqldata = (void*)&section;
#line 70 "schedule.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 70 "schedule.sqc"
      sql_setdlist[4].sqltype = 460; sql_setdlist[4].sqllen = 10;
#line 70 "schedule.sqc"
      sql_setdlist[4].sqldata = (void*)time;
#line 70 "schedule.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 70 "schedule.sqc"
      sql_setdlist[5].sqltype = 460; sql_setdlist[5].sqllen = 7;
#line 70 "schedule.sqc"
      sql_setdlist[5].sqldata = (void*)room;
#line 70 "schedule.sqc"
      sql_setdlist[5].sqlind = 0L;
#line 70 "schedule.sqc"
      sql_setdlist[6].sqltype = 460; sql_setdlist[6].sqllen = 70;
#line 70 "schedule.sqc"
      sql_setdlist[6].sqldata = (void*)sname;
#line 70 "schedule.sqc"
      sql_setdlist[6].sqlind = 0L;
#line 70 "schedule.sqc"
      sqlasetdata(3,0,7,sql_setdlist,0L,0L);
    }
#line 70 "schedule.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 70 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 70 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 70 "schedule.sqc"
  sqlastop(0L);
}

#line 70 "schedule.sqc"

        
/*
EXEC SQL WHENEVER SQLCODE=100 GO TO nodata;
*/

/*
SQL0104N  An unexpected token "SQLCODE" was found following 
"WHENEVER".  Expected tokens may include:  "SQLERROR".

*/

        printf("%s:  %s (%s) %d %s %s\n", day, cname, cnum, section, time, room);
    };

nodata:
    
/*
EXEC SQL CLOSE schedule;
*/

{
#line 76 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 76 "schedule.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 76 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 76 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 76 "schedule.sqc"
  sqlastop(0L);
}

#line 76 "schedule.sqc"

    printf("Schedule for %s does not exist.", term);
    printf("-------\n");
    
/*
EXEC SQL COMMIT;
*/

{
#line 79 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 79 "schedule.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 79 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 79 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 79 "schedule.sqc"
  sqlastop(0L);
}

#line 79 "schedule.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 80 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 80 "schedule.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 80 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 80 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 80 "schedule.sqc"
  sqlastop(0L);
}

#line 80 "schedule.sqc"

    exit(0);
    
end:
    
/*
EXEC SQL CLOSE schedule;
*/

{
#line 84 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 84 "schedule.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 84 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 84 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 84 "schedule.sqc"
  sqlastop(0L);
}

#line 84 "schedule.sqc"

    printf("-------\n");
    
/*
EXEC SQL COMMIT;
*/

{
#line 86 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 86 "schedule.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 86 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 86 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 86 "schedule.sqc"
  sqlastop(0L);
}

#line 86 "schedule.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 87 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 87 "schedule.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 87 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 87 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 87 "schedule.sqc"
  sqlastop(0L);
}

#line 87 "schedule.sqc"

    exit(0);

error:
    check_error("My error",&sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 92 "schedule.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 94 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 94 "schedule.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 94 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 94 "schedule.sqc"
  sqlastop(0L);
}

#line 94 "schedule.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 95 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 95 "schedule.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 95 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 95 "schedule.sqc"
  sqlastop(0L);
}

#line 95 "schedule.sqc"

    exit(1);
}