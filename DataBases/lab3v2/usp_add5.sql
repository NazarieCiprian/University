use lab1tema
go
-- add a foreign key
create procedure usp_add5
as
begin
	alter table Auxiliaries
	add constraint fk__client foreign key(cid) references Clients(client_id)
end
go

