select DISTINCT name from people where name IS not "Kevin Bacon" and id IN
(select person_id from stars A where A.movie_id IN
 (select movie_id from stars B where B.person_id IN
  (select id from people where name = "Kevin Bacon" and birth = 1958)));