select DISTINCT name from people P
join directors D on D.person_id = P.id
join movies M on M.id = D.movie_id
join ratings R on R.movie_id = M.id where R.rating >= 9.0;