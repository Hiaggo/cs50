select name from people P
join stars S on P.id = S.person_id
JOIN movies M on S.movie_id = M.id where M.year = 2004 group by name order by birth;