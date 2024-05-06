@echo off

set "MONITOR_HOME_DIR=%cd%\..\.."

set "display="
if "%DISPLAY%"=="" (
    set "display=:1"
) else (
    set "display=%DISPLAY%"
)

set "local_host=%COMPUTERNAME%"
set "user=%USERNAME%"
for /f "tokens=*" %%a in ('id -u') do set "uid=%%a"
for /f "tokens=*" %%b in ('id -g -n') do set "group=%%b"
for /f "tokens=*" %%c in ('id -g') do set "gid=%%c"

echo stop and rm docker
docker stop ros_noetic_proto > nul
docker rm -v -f ros_noetic_proto > nul

echo start docker
docker run -it -d ^
--privileged=true ^
--name ros_noetic_proto ^
-e DISPLAY=%display% ^
-e DOCKER_USER="%user%" ^
-e USER="%user%" ^
-e DOCKER_USER_ID="%uid%" ^
-e DOCKER_GRP="%group%" ^
-e DOCKER_GRP_ID="%gid%" ^
-e XDG_RUNTIME_DIR=%XDG_RUNTIME_DIR% ^
-v "%MONITOR_HOME_DIR%:/work" ^
-v "%XDG_RUNTIME_DIR%:%XDG_RUNTIME_DIR%" ^
-p 3344:22 ^
ros_protobuf:noetic
