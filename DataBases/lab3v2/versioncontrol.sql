use lab1tema
go

create procedure versionontrolsmart
@version int
as
begin
	declare @currentVersion int
	declare @procedure varchar(50)
	select @currentVersion= v.version
	from Versions v

	if @currentVersion = @version
		print 'No more changes'

	while @currentVersion < @version
	begin
		set @currentVersion = @currentVersion +1
		set @procedure = 'usp_add' + cast(@currentVersion as varchar(50))

		print @procedure
		execute @procedure
	end

	while @currentVersion > @version
	begin
		set @procedure = 'usp_reverse' +cast(@currentVersion as varchar(50))
		set @currentVersion = @currentVersion -1

		print @procedure
		execute @procedure
	end
	
	update Versions
	set version = @version

end
go
execute versionontrolsmart @version=0;

