mkdir CSC2244
mkdir Marks
mkdir Exam

cd CSC2244


mkdir practical
cd practical
echo.> practical.txt
type nul > practical.docx
type nul > practical.pptx
cd..


mkdir theory
cd theory
echo.> theory.txt
type nul > theory.docx
type nul > theory.pptx

cd..


mkdir exam
cd exam
echo.> exam.txt
type nul > exam.docx
type nul > exam.pptx
cd..

type nul >"Icamarks.xlxs"
type nul >"final_marks.xlxs"
move Icamarks.xlxs Marks
move final_marks.xlxs Marks






