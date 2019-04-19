CREATE TABLE `Sensors_Type` (
	`Type_ID` INT NOT NULL AUTO_INCREMENT,
	`Type_Name` TEXT,
	PRIMARY KEY (`Type_ID`)
);

CREATE TABLE `Sensor_List` (
	`Sensor_ID` INT NOT NULL AUTO_INCREMENT,
	`Type_ID` INT,
	`name` VARCHAR(255),
	PRIMARY KEY (`Sensor_ID`)
);

CREATE TABLE `Data` (
	`Sensor_Index` INT NOT NULL AUTO_INCREMENT,
	`Time` DATETIME,
	`Value` FLOAT NOT NULL,
	PRIMARY KEY (`Sensor_Index`)
);

CREATE TABLE `Individual` (
	`Sensor_ID` INT NOT NULL AUTO_INCREMENT,
	`Sensor_Index` INT NOT NULL,
	`coordinate` INT NOT NULL,
	PRIMARY KEY (`Sensor_Index`)
);

ALTER TABLE `Sensor_List` ADD CONSTRAINT `Sensor_List_fk0` FOREIGN KEY (`Type_ID`) REFERENCES `Sensors_Type`(`Type_ID`);

ALTER TABLE `Data` ADD CONSTRAINT `Data_fk0` FOREIGN KEY (`Sensor_Index`) REFERENCES `Individual`(`Sensor_Index`);

ALTER TABLE `Individual` ADD CONSTRAINT `Individual_fk0` FOREIGN KEY (`Sensor_ID`) REFERENCES `Sensor_List`(`Sensor_ID`);

