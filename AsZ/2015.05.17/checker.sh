while true; do
./gen>nim.in #出数据
./F>std.out #正确（暴力）程序
python my.py>my.out #被测程序
if diff std.out my.out; then #比较两个输出文件
echo "AC" #结果相同显示AC
else
echo "WA" #结果不同显示WA，并退出
exit 0
fi #if的结束标志,与c语言相反，0为真
done #while的结束标志

