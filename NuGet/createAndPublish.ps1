PARAM 
(
	[Parameter(Mandatory=$true)]
	[string] $ApiKey
)

Write-Host 'Copying missing files...'
Copy-Item ..\Libraries\mtmanapi\*.dll
Copy-Item ..\src\Release\*.dll
Copy-Item ..\src\Release\*.xml

$version = (Get-Item P23.MetaTrader4.Manager.ClrWrapper.dll).VersionInfo.FileVersion

Write-Host 'Updating targets file...'
$nuspecFile = 'MetaTrader4.Manager.Wrapper.nuspec'
[xml]$nuspec = Get-Content $nuspecFile
$nuspec.package.metadata.version = $version
$nuspec.Save("$pwd\$nuspecFile")

#Update version in targets file
$targetsFile = 'MetaTrader4.Manager.Wrapper.targets'
[xml]$targets = Get-Content $targetsFile
$includeValue = "`$(SolutionDir)\packages\MetaTrader4.Manager.Wrapper.$version\unmanaged\*.dll"
$targets.Project.Target.ItemGroup.MyPackageSourceFile.Include = $includeValue
$targets.Save("$pwd\$targetsFile")

Write-Host 'Publishing package...'
.\nuget.exe pack $nuspecFile
.\nuget.exe setapikey $ApiKey
.\nuget.exe push "MetaTrader4.Manager.Wrapper.$version.nupkg"

Write-Host 'Removing files...'
Remove-Item *.dll
Remove-Item *.xml
Remove-Item *.nupkg

Write-Host 'Done'