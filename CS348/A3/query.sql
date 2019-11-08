SELECT e.term \
            FROM Enrollment e \
            WHERE not exists( \
                SELECT * \
                FROM Mark m \
                WHERE m.cnum = e.cnum \
                    AND m.term = e.term \
                    AND m.section = e.section \
                )