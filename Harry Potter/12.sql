select title from movies M
join stars S on S.movie_id = M.id
join people P on P.id = S.person_id
where P.name = "Johnny Depp"
INTERSECT
select title from movies M
join stars S on S.movie_id = M.id
join people P on P.id = S.person_id
where P.name = "Helena Bonham Carter";