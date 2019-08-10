DROP TABLE IF EXISTS Authors;
CREATE TABLE Authors (
  AuthorID integer not null primary key autoincrement,
  Name varchar(60) not null,
  Country varchar(40) not null
);

INSERT INTO Authors (Name, Country) VALUES ('J.K Rowling', 'United Kingdom');
INSERT INTO Authors (Name, Country) VALUES ('Mark Twain', 'United States');
INSERT INTO Authors (Name, Country) VALUES ('Miguel De Cervantes', 'Spain');

DROP TABLE IF EXISTS Books;
CREATE TABLE Books (
  BookID integer not null primary key autoincrement,
  Title varchar(100) not null,
  Genre varchar(20) not null,
  PublicationYear varchar(4) not null,
  AuthorID integer not null
);

INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Philosophers Stone', 'Fantasy', '1997', 1
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Chamber of Secrets', 'Fantasy', '1999', 1
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Prizoner of Azkaban', 'Fantasy', '1999', 1
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Goblet of Fire', 'Fantasy', '2000', 1
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Order of Phoenix', 'Fantasy', '2003', 1
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Half-Blood Prince', 'Fantasy', '2005', 1
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Harry Potter and the Deathly Hallows', 'Fantasy', '2007', 1
);

INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Adventures of Huckleberry Finn', 'Picaresque Fiction', '1884', 2
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'The Adventures of Tom Sawyer', 'Folklore', '1876', 2
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'The Celebrated Junmping Frog of Calaveras County', 'Fiction', '1865', 2
);

INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Don Quixote', 'Novel', '1605', 3
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'La Galatea', 'Fiction', '1585', 3
);
INSERT INTO Books (
  Title, Genre, PublicationYear, AuthorID
) VALUES (
  'Viaje al Parnaiso', 'Poetry', '1614', 3
);
