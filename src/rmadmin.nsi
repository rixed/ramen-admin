!define VERSION "666"
!define PRODUCT "RmAdmin - ${VERSION}"
Name "${PRODUCT}"
OutFile "RmAdmin.${VERSION}.installer.exe"
ShowInstDetails show
  
InstallDir "$PROGRAMFILES\${PRODUCT}"

Section "Install"
  SetOutPath "$INSTDIR"
  File /a /r "app\"
  CreateShortCut "$DESKTOP\${PRODUCT}.lnk" "$INSTDIR\RmAdmin.exe"
SectionEnd
