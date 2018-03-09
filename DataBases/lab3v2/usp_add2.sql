use lab1tema
go
--add default constraint 
create procedure usp_add2
as
begin
	alter table Genres
	add constraint desc_const default 'it is fun' for description
end

go