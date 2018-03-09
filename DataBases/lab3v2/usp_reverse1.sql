use lab1tema
go
--reverse type change
create procedure usp_reverse1
as
begin
	alter table Orders
	alter column order_no int
end
go