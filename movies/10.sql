SELECT DISTINCT name FROM people
INNER JOIN directors ON people.id = directors.person_id
INNER JOIN movies ON movies.id = directors.movie_id
INNER JOIN ratings on movies.id = ratings.movie_id
WHERE rating >= 9.0;

