use lab1tema
go
--reverse add a new column
create procedure usp_reverse4
as
begin
	alter table Backs
	drop column back_number
end

go