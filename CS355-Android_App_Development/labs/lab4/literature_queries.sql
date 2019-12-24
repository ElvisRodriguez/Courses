--Queries for Problem Statement
SELECT Name, Title FROM Authors, Books
WHERE Authors.AuthorID=Books.AuthorID AND Books.AuthorID=1;

SELECT Name, Title, Genre FROM Authors, Books
WHERE Authors.AuthorID=Books.AuthorID AND Genre='Fiction';
