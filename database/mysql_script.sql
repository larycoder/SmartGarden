CREATE TABLE Sensors_Type (
	Type_ID INT NOT NULL ,
	Type_Name VARCHAR(255),
	PRIMARY KEY (Type_ID)
);

CREATE TABLE Sensor_List (
	Sensor_ID INT NOT NULL ,
	Type_ID INT,
	name VARCHAR(255),
	PRIMARY KEY (Sensor_ID)
);

CREATE TABLE Data (
	Sensor_Index INT NOT NULL ,
	Time DATETIME,
	Value FLOAT NOT NULL,
	PRIMARY KEY (Sensor_Index)
);

CREATE TABLE Individual_Sensor (
	Sensor_ID INT NOT NULL ,
	Sensor_Index INT NOT NULL AUTO_INCREMENT,
	coordinate INT NOT NULL,
	PRIMARY KEY (Sensor_Index)
);

ALTER TABLE Sensor_List ADD CONSTRAINT Sensor_List_fk0 FOREIGN KEY (Type_ID) REFERENCES Sensors_Type(Type_ID);

ALTER TABLE Data ADD CONSTRAINT Data_fk0 FOREIGN KEY (Sensor_Index) REFERENCES Individual_Sensor(Sensor_Index);

ALTER TABLE Individual_Sensor ADD CONSTRAINT Individual_fk0 FOREIGN KEY (Sensor_ID) REFERENCES Sensor_List(Sensor_ID);

