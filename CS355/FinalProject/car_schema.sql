DROP TABLE IF EXISTS CarStyles;
CREATE TABLE CarStyles (
  CarID integer not null primary key autoincrement,
  Style varchar(30) not null,
  DefaultImg varchar(30) not null
);

DROP TABLE IF EXISTS Models;
CREATE TABLE Models (
  DetailsID integer not null primary key autoincrement,
  Model varchar(60) not null,
  Year varchar(4) not null,
  Company varchar(20) not null,
  CarID integer not null,
  ImageName varchar(60) not null
);

DROP TABLE IF EXISTS CarDetails;
CREATE TABLE CarDetails (
  DetailsID integer not null primary key autoincrement,
  MSRP varchar(15) not null,
  MilesPerGallon varchar(25) not null,
  HorsePower varchar(25) not null
);

DROP TABLE IF EXISTS ModelsToDealers;
CREATE TABLE ModelsToDealers (
  DealershipID integer not null primary key autoincrement,
  DetailsID integer not null
);

DROP TABLE IF EXISTS CarDealerships;
CREATE TABLE CarDealerships (
  DealershipID integer not null primary key autoincrement,
  Name varchar(50) not null,
  Location varchar(70) not null
);
