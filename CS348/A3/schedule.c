static char sqla_program_id[292] = 
{
 172,0,65,69,65,85,65,73,108,65,117,74,87,72,76,106,48,49,49,49,
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
   char pname[70], sname[70], cname[70], cnum[7], day[20], time[10], room[7], input[8], term[10];
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

    strncpy(input,argv[1],8);

    
/*
EXEC SQL SELECT s.sname INTO :sname
            FROM Student s
            WHERE s.snum = :input;
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
      sql_setdlist[0].sqldata = (void*)input;
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
EXEC SQL SELECT p.pname INTO :pname
            FROM Professor p
            WHERE p.pnum = :input;
*/

{
#line 36 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 36 "schedule.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 36 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 8;
#line 36 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 36 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 36 "schedule.sqc"
      sqlasetdata(2,0,1,sql_setdlist,0L,0L);
    }
#line 36 "schedule.sqc"
  sqlaaloc(3,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 36 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 70;
#line 36 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)pname;
#line 36 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 36 "schedule.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 36 "schedule.sqc"
  sqlacall((unsigned short)24,2,2,3,0L);
#line 36 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 36 "schedule.sqc"
  sqlastop(0L);
}

#line 36 "schedule.sqc"
 

    
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
#line 46 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 46 "schedule.sqc"
  sqlaaloc(3,1,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 46 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 10;
#line 46 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)term;
#line 46 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 46 "schedule.sqc"
      sqlasetdata(3,0,1,sql_setdlist,0L,0L);
    }
#line 46 "schedule.sqc"
  sqlacall((unsigned short)24,3,0,3,0L);
#line 46 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 46 "schedule.sqc"
  sqlastop(0L);
}

#line 46 "schedule.sqc"
  

    
/*
EXEC SQL DECLARE schedule CURSOR FOR 
            SELECT c.cname, c.cnum, se.day, se.section, se.time, se.room
            FROM Student s, Schedule se, Enrollment e, Course c
            WHERE s.snum = :input
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
            UNION
            SELECT ce.cname, ce.cnum, se.day, se.section, se.time, se.room
            FROM Schedule se, Class c, Professor p, Course ce
            WHERE p.pnum = :input
                AND c.pnum = p.pnum
                AND c.cnum = se.cnum
                AND c.term = se.term
                AND c.section = se.section
                AND c.cnum = ce.cnum
                AND not exists (
                    SELECT *
                    FROM Mark m, Enrollment e
                    WHERE m.term = e.term
                        AND m.cnum = e.cnum  
                        AND m.section = e.section
                        AND m.cnum = c.cnum
                        AND m.term = c.term
                        AND m.section = c.section
                )
            ;
*/

#line 81 "schedule.sqc"


    
/*
EXEC SQL OPEN schedule;
*/

{
#line 83 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 83 "schedule.sqc"
  sqlaaloc(2,2,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 83 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 8;
#line 83 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)input;
#line 83 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 83 "schedule.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 8;
#line 83 "schedule.sqc"
      sql_setdlist[1].sqldata = (void*)input;
#line 83 "schedule.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 83 "schedule.sqc"
      sqlasetdata(2,0,2,sql_setdlist,0L,0L);
    }
#line 83 "schedule.sqc"
  sqlacall((unsigned short)26,4,2,0,0L);
#line 83 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 83 "schedule.sqc"
  sqlastop(0L);
}

#line 83 "schedule.sqc"

    
/*
EXEC SQL WHENEVER NOT FOUND GO TO end;
*/

#line 84 "schedule.sqc"

    if (sname[0] == '\0'){
        printf("Schedule for %s (%s) and term<%s>\n", pname, input, term);
    } else {
        printf("Schedule for %s (%s) and term<%s>\n", sname, input, term);
    }

    printf("-------\n");
    for (;;) {
        
/*
EXEC SQL FETCH schedule INTO :cname, :cnum, :day, :section, :time, :room;
*/

{
#line 93 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 93 "schedule.sqc"
  sqlaaloc(3,6,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[6];
#line 93 "schedule.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 70;
#line 93 "schedule.sqc"
      sql_setdlist[0].sqldata = (void*)cname;
#line 93 "schedule.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 93 "schedule.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 7;
#line 93 "schedule.sqc"
      sql_setdlist[1].sqldata = (void*)cnum;
#line 93 "schedule.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 93 "schedule.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 20;
#line 93 "schedule.sqc"
      sql_setdlist[2].sqldata = (void*)day;
#line 93 "schedule.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 93 "schedule.sqc"
      sql_setdlist[3].sqltype = 500; sql_setdlist[3].sqllen = 2;
#line 93 "schedule.sqc"
      sql_setdlist[3].sqldata = (void*)&section;
#line 93 "schedule.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 93 "schedule.sqc"
      sql_setdlist[4].sqltype = 460; sql_setdlist[4].sqllen = 10;
#line 93 "schedule.sqc"
      sql_setdlist[4].sqldata = (void*)time;
#line 93 "schedule.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 93 "schedule.sqc"
      sql_setdlist[5].sqltype = 460; sql_setdlist[5].sqllen = 7;
#line 93 "schedule.sqc"
      sql_setdlist[5].sqldata = (void*)room;
#line 93 "schedule.sqc"
      sql_setdlist[5].sqlind = 0L;
#line 93 "schedule.sqc"
      sqlasetdata(3,0,6,sql_setdlist,0L,0L);
    }
#line 93 "schedule.sqc"
  sqlacall((unsigned short)25,4,0,3,0L);
#line 93 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 93 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 93 "schedule.sqc"
  sqlastop(0L);
}

#line 93 "schedule.sqc"

        printf("%s:  %s (%s) %d %s %s\n", day, cname, cnum, section, time, room);
    };

nodata:
    
/*
EXEC SQL CLOSE schedule;
*/

{
#line 98 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 98 "schedule.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 98 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 98 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 98 "schedule.sqc"
  sqlastop(0L);
}

#line 98 "schedule.sqc"

    printf("Schedule for %s does not exist.", term);
    printf("-------\n");
    
/*
EXEC SQL COMMIT;
*/

{
#line 101 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 101 "schedule.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 101 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 101 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 101 "schedule.sqc"
  sqlastop(0L);
}

#line 101 "schedule.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 102 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 102 "schedule.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 102 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 102 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 102 "schedule.sqc"
  sqlastop(0L);
}

#line 102 "schedule.sqc"

    exit(0);
    
end:
    
/*
EXEC SQL CLOSE schedule;
*/

{
#line 106 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 106 "schedule.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 106 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 106 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 106 "schedule.sqc"
  sqlastop(0L);
}

#line 106 "schedule.sqc"

    printf("-------\n");
    
/*
EXEC SQL COMMIT;
*/

{
#line 108 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 108 "schedule.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 108 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 108 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 108 "schedule.sqc"
  sqlastop(0L);
}

#line 108 "schedule.sqc"

    
/*
EXEC SQL CONNECT RESET;
*/

{
#line 109 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 109 "schedule.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 109 "schedule.sqc"
  if (sqlca.sqlcode < 0)
  {
    sqlastop(0L);
    goto error;
  }
#line 109 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 109 "schedule.sqc"
  sqlastop(0L);
}

#line 109 "schedule.sqc"

    exit(0);

error:
    check_error("My error",&sqlca);
    
/*
EXEC SQL WHENEVER SQLERROR CONTINUE;
*/

#line 114 "schedule.sqc"


    
/*
EXEC SQL ROLLBACK;
*/

{
#line 116 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 116 "schedule.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 116 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 116 "schedule.sqc"
  sqlastop(0L);
}

#line 116 "schedule.sqc"

    
/*
EXEC SQL CONNECT reset;
*/

{
#line 117 "schedule.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 117 "schedule.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 117 "schedule.sqc"
  if (sqlca.sqlcode == 100)
  {
    sqlastop(0L);
    goto end;
  }
#line 117 "schedule.sqc"
  sqlastop(0L);
}

#line 117 "schedule.sqc"

    exit(1);
}