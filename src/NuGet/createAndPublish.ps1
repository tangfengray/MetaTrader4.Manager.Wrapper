PARAM 
(
	[Parameter(Mandatory=$true)]
	[string] $ApiKey
)

Write-Host 'Copying missing files...'
Copy-Item ..\Libraries\mtmanapi\*.dll
Copy-Item ..\Projects\Release\*.dll
Copy-Item ..\Projects\Release\*.xml

Write-Host 'Updating targets file...'
$nuspecFile = 'MetaTrader4.Manager.Wrapper.nuspec'
[xml]$nuspec = Get-Content $nuspecFile
$nuspecVersion = $nuspec.package.metadata.version

#Update version in targets file
$targetsFile = 'MetaTrader4.Manager.Wrapper.targets'
[xml]$targets = Get-Content $targetsFile
$includeValue = "`$(SolutionDir)\packages\MetaTrader4.Manager.Wrapper.$nuspecVersion\unmanaged\*.dll"
$targets.Project.Target.ItemGroup.MyPackageSourceFile.Include = $includeValue
$targets.Save("$pwd\$targetsFile")

Write-Host 'Publishing package...'
.\nuget.exe pack $nuspecFile
.\nuget.exe setapikey $ApiKey
#.\nuget.exe push "MetaTrader4.Manager.Wrapper.$nuspecVersion.nupkg"

Write-Host 'Removing files...'
Remove-Item *.dll
Remove-Item *.xml
Remove-Item *.nupkg

Write-Host 'Done'