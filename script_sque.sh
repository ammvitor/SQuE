gmx covar -f traj.trr -s traj.tpr
for i in `seq 1 60`
do
gmx anaeig -f traj.trr -s traj.tpr -first $i -last $i -2d proj_$i.xvg 
done
for i in `seq 1 60`
do
echo proj_$i.xvg >> proj_list.dat 
done

squee -i proj_list.dat -b 0.1
