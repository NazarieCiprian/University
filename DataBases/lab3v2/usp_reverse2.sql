use lab1tema
go
-- reverse add constraint
create procedure usp_reverse2
as
begin
	alter table Genres
	drop constraint desc_const
end