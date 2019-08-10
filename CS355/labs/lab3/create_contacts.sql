drop table if exists contacts;
create table contacts (
  id integer not null primary key autoincrement,
  name varchar(40) not null
);

insert into contacts (name) values ('Elvis Rodriguez');
insert into contacts (name) values ('Karen Rodriguez');
insert into contacts (name) values ('Katherine Rodriguez');
insert into contacts (name) values ('Chris Griffith');
insert into contacts (name) values ('Danny Bui');
insert into contacts (name) values ('William Lam');
insert into contacts (name) values ('Dexter Morgan');
insert into contacts (name) values ('Rick Sanchez');
insert into contacts (name) values ('Jonathan James');
insert into contacts (name) values ('Joel Turbi');
