use lab1tema
go
-- drop foreign key constraint
create procedure usp_reverse5
as
begin
	alter table Auxiliaries
	drop constraint fk__client
end

execute usp_reverse5
execute usp_add5