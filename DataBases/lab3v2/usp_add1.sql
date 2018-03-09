use lab1tema
go
--changes the type of column order_no from int ot varchar
create procedure usp_add1
as 
begin
	alter table Orders
	alter column order_no varchar(50)
end
