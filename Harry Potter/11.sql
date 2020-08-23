select title from movies M
Join ratings R on R.movie_id = M.id
join stars S on S.movie_id = M.id
Join people P on P.id = S.person_id
where P.name = "Chadwick Boseman" order by rating desc limit 5;