SELECT name FROM people
WHERE people.id IN (
    SELECT person_id FROM stars WHERE stars.movie_id IN (
        SELECT movies.id FROM movies WHERE title = 'Toy Story'));
