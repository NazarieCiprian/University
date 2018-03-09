use lab1tema
go
-- add a new column

create procedure usp_add4
as 
begin
	alter table Backs
	add back_number int
end
go