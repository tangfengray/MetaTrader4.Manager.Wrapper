Param(
   [Parameter(Mandatory=$true)]
   [string]$newVersion,
   [Parameter(Mandatory=$true)]
   [string]$solutionDirectory
) 

$fileName = [IO.Path]::Combine($solutionDirectory, "P23.MetaTrader4.Manager.ClrWrapper\VersionNo.h")
$resourceFile = Get-Content $fileName -Raw
$fileVer = ($newVersion -replace "\.", ",")
$resourceFile = $resourceFile -replace "\d+,\d+,\d+,\d+", $fileVer
$resourceFile = $resourceFile -replace "\d+\.\d+\.\d+\.\d+", $newVersion
$resourceFile = $resourceFile.Trim()
Out-File -FilePath $fileName -InputObject $resourceFile

$assemblyInfoFileName = [IO.Path]::Combine($solutionDirectory, "P23.MetaTrader4.Manager.ClrWrapper\AssemblyInfo.cpp")
$assemblyInfoFile = Get-Content $assemblyInfoFileName -Raw
$assemblyInfoFile = $assemblyInfoFile -replace "AssemblyVersionAttribute[(]"".+""", [String]::Format("AssemblyVersionAttribute(""{0}""", $newVersion)
$assemblyInfoFile = $assemblyInfoFile.Trim()
Out-File -FilePath $assemblyInfoFileName -InputObject $assemblyInfoFile