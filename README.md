# SQuE
Structural Quantifier of Entropy

Used for analyis of GROMACS output. It integrates the outputed principal components given by the trajectory and outputs distribution entropy
using a first degree approximation. This decorrelates the degrees of freedom.

USAGE
 -i <2dproj_xvg> -o <output_prefix> -n n_clusters -t trjname

Using a KNN algorithm, you set the number of clusters, and clusterizes the distribution for you. If you add the trajectory used to chreate the 2dproj, 
it will also separate the trajectory for you. Only works with trajectories with a PDB format.

