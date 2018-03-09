use lab1tema
go
--add a new table
create procedure usp_add3
as
begin
	create table Auxiliaries
	(
		id int primary key identity,
		aux_name varchar(20),
		aux_date datetime,
		cid int
	)
end
go