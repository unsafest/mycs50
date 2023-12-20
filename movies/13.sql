SELECT name FROM people
INNER JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN (
    SELECT movie_id from stars
    INNER JOIN people ON stars.person_id = people.id
    WHERE name = 'Kevin Bacon' AND birth = 1958)
AND name != 'Kevin Bacon';