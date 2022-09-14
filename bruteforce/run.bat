@echo off
gen >in
sol <in >out
brute <in >ok
fc out ok
if ErrorLevel 1 exit /b
run
