--Initial query for main activity:
SELECT Style, DefaultImg FROM CarStyles;

--Query for subsequent activity (based on the car style chosen):
SELECT Model, Year, Company, ImageName FROM Models, CarStyles,
WHERE Models.CarID=CarStyles.CarID AND CarStyles.Style="SUV";

--Query for activity opened upon choosing a car model:
SELECT Model, Name, Location, MSRP, MilesPerGallon, Horsepower, ImageName
FROM CarDealerships, CarDetails, Models, ModelsToDealers
WHERE CarDetails.DetailsID=Models.DetailsID
AND Models.DetailsID=ModelsToDealers.DetailsID
AND CarDealerships.DealershipID=ModelstoDealers.DealershipID
AND Model="Kia Telluride";

--Note that Models.ImageName is used to retrieve the appropriate image for
--a given car model from the app's drawable folder
