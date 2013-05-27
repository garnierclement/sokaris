#include "Map.h"

using namespace std;
namespace sokaris
{
	Map::Map()
	{
	}

	Map::~Map()
	{
	}

	int Map::outputResultToFile(string filename, double angleX_observator, 
		double angleY_observator, double angleZ_observator)
	{
		int number_Spot = this->listGazes.size();
		int number_Plane = this->listPlane.size();
		int i=0;
		FileStorage fs(filename, FileStorage::WRITE);
		fs << "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
		fs << "<COLLADA xmlns=\"http://www.collada.org/2005/11/COLLADASchema\" version=\"1.4.1\">";
		fs << "  <asset>";
		fs << "    <contributor>";
		fs << "      <author>Sokaris</author>";
		fs << "      <authoring_tool>Blender 2.67.0 r56533</authoring_tool>";
		fs << "    </contributor>";
		fs << "    <created>2013-05-27T13:29:29</created>";
		fs << "    <modified>2013-05-27T13:29:29</modified>";
		fs << "    <unit name=\"meter\" meter=\"1\"/>";
		fs << "    <up_axis>Z_UP</up_axis>";
		fs << "  </asset>";
		fs << "  <library_cameras>";
		fs << "    <camera id=\"Camera-camera\" name=\"Observateur\">";
		fs << "      <optics>";
		fs << "        <technique_common>";
		fs << "          <perspective>";
		fs << "            <xfov sid=\"xfov\">90</xfov>";
		fs << "            <aspect_ratio>1.3333</aspect_ratio>";
		fs << "            <znear sid=\"znear\">0.1</znear>";
		fs << "            <zfar sid=\"zfar\">100</zfar>";
		fs << "          </perspective>";
		fs << "        </technique_common>";
		fs << "      </optics>";
		fs << "    </camera>";
		fs << "  </library_cameras>";
		fs << "  <library_lights>";
		for(i=0; i<number_Spot; i++){
			fs << "    <light id=\"Spot_" << i << "-light\" name=\"Spot." <<i<< "\">";
			fs << "      <technique_common>";
			fs << "        <spot>";
			fs << "          <color sid=\"color\">1 1 1</color>";
			fs << "          <constant_attenuation>1</constant_attenuation>";
			fs << "          <linear_attenuation>0</linear_attenuation>";
			fs << "          <quadratic_attenuation>0.001599967</quadratic_attenuation>";
			fs << "          <falloff_angle sid=\"fall_off_angle\">15</falloff_angle>";
			fs << "          <falloff_exponent sid=\"fall_off_exponent\">0.15</falloff_exponent>";
			fs << "        </spot>";
			fs << "      </technique_common>";
			fs << "      <extra>";
			fs << "        <technique profile=\"blender\">";
			fs << "          <clipend>40</clipend>";
			fs << "          <clipsta>0.5</clipsta>";
			fs << "          <dist sid=\"blender_dist\">25</dist>";
			fs << "          <energy sid=\"blender_energy\">0.1</energy>";
			fs << "          <falloff_type>0</falloff_type>";
			fs << "          <spotblend>0.15</spotblend>";
			fs << "          <spotsize>15</spotsize>";
			fs << "          <spread>1</spread>";
			fs << "          <type>2</type>";
			fs << "        </technique>";
			fs << "      </extra>";
			fs << "    </light>";
		}
		fs << "  </library_lights>";
		fs << "  <library_images/>";
		fs << "  <library_geometries>";
		for (i=0; i<number_Plane; i++){
			fs << "    <geometry id=\"Plane_"<<i<<"-mesh\" name=\"Plane."<<i<<"\">";
			fs << "      <mesh>";
			fs << "        <source id=\"Plane_"<<i<<"-mesh-positions\">";
			fs << "          <float_array id=\"Plane_"<<i<<"-mesh-positions-array\" count=\"12\">1 -1 0 -1 -1 0 1 1 0 -1 1 0</float_array>";
			fs << "          <technique_common>";
			fs << "            <accessor source=\"#Plane_"<<i<<"-mesh-positions-array\" count=\"4\" stride=\"3\">";
			fs << "              <param name=\"X\" type=\"float\"/>";
			fs << "              <param name=\"Y\" type=\"float\"/>";
			fs << "              <param name=\"Z\" type=\"float\"/>";
			fs << "            </accessor>";
			fs << "          </technique_common>";
			fs << "        </source>";
			fs << "        <source id=\"Plane_"<<i<<"-mesh-normals\">";
			fs << "          <float_array id=\"Plane_"<<i<<"-mesh-normals-array\" count=\"6\">0 0 1 0 0 1</float_array>";
			fs << "          <technique_common>";
			fs << "            <accessor source=\"#Plane_"<<i<<"-mesh-normals-array\" count=\"2\" stride=\"3\">";
			fs << "              <param name=\"X\" type=\"float\"/>";
			fs << "              <param name=\"Y\" type=\"float\"/>";
			fs << "              <param name=\"Z\" type=\"float\"/>";
			fs << "            </accessor>";
			fs << "          </technique_common>";
			fs << "        </source>";
			fs << "        <vertices id=\"Plane_"<<i<<"-mesh-vertices\">";
			fs << "          <input semantic=\"POSITION\" source=\"#Plane_"<<i<<"-mesh-positions\"/>";
			fs << "        </vertices>";
			fs << "        <polylist count=\"2\">";
			fs << "          <input semantic=\"VERTEX\" source=\"#Plane_"<<i<<"-mesh-vertices\" offset=\"0\"/>";
			fs << "          <input semantic=\"NORMAL\" source=\"#Plane_"<<i<<"-mesh-normals\" offset=\"1\"/>";
			fs << "          <vcount>3 3 </vcount>";
			fs << "          <p>1 0 0 0 2 0 3 1 1 1 2 1</p>";
			fs << "        </polylist>";
			fs << "      </mesh>";
			fs << "      <extra><technique profile=\"MAYA\"><double_sided>1</double_sided></technique></extra>";
			fs << "    </geometry>";
			fs << "";
		}
		fs << "  </library_geometries>";
		fs << "  <library_controllers/>";
		fs << "  <library_visual_scenes>";
		fs << "    <visual_scene id=\"Scene\" name=\"Scene\">";
		fs << "      <node id=\"Camera\" name=\"Camera\" type=\"NODE\">";
		fs << "        <translate sid=\"location\">17.11059 16.52051 18.54392</translate>";
		fs << "        <rotate sid=\"rotationZ\">0 0 1 "<<angleZ_observator<<"</rotate>";
		fs << "        <rotate sid=\"rotationY\">0 1 0 "<<angleY_observator<<"</rotate>";
		fs << "        <rotate sid=\"rotationX\">1 0 0 "<<angleX_observator<<"</rotate>";
		fs << "        <scale sid=\"scale\">1 1 1</scale>";
		fs << "        <instance_camera url=\"#Camera-camera\"/>";
		fs << "      </node>";
		for(i=0; i<number_Spot; i++){
			fs << "      <node id=\"Spot_"<<i<<"\" name=\"Spot_"<<i<<"\" type=\"NODE\">";
			fs << "        <translate sid=\"location\">"<<this->listGazes[i]->getPosition().x<<" "
							<<this->listGazes[i]->getPosition().y<<" "<<this->listGazes[i]->getPosition().z<<"</translate>";
			fs << "        <rotate sid=\"rotationZ\">0 0 1 "<<this->listGazes[i]->getPosition().z<<"</rotate>";
			fs << "        <rotate sid=\"rotationY\">0 1 0 "<<this->listGazes[i]->getPosition().y<<"</rotate>";
			fs << "        <rotate sid=\"rotationX\">1 0 0 "<<this->listGazes[i]->getPosition().x<<"</rotate>";
			fs << "        <scale sid=\"scale\">1 1 1</scale>";
			fs << "        <instance_light url=\"#Spot_"<<i<<"-light\"/>";
			fs << "      </node>";
		}
		for(i=0;i<number_Plane;i++){
			fs << "      <node id=\"Plane_"<<i<<"\" name=\"Plane_"<<i<<"\" type=\"NODE\">";
			fs << "        <translate sid=\"location\">"<<this->listPlane[i]->point.x<<" "
							<<this->listPlane[i]->point.y<<" "<<this->listPlane[i]->point.z<<"</translate>";
			fs << "        <rotate sid=\"rotationZ\">0 0 1 "<<this->listPlane[i]->angles.z<<"</rotate>";
			fs << "        <rotate sid=\"rotationY\">0 1 0 "<<this->listPlane[i]->angles.y<<"</rotate>";
			fs << "        <rotate sid=\"rotationX\">1 0 0 "<<this->listPlane[i]->angles.x<<"</rotate>";
			fs << "        <scale sid=\"scale\">"<<this->listPlane[i]->width<<" "<<this->listPlane[i]->height<<" 1</scale>";
			fs << "        <instance_geometry url=\"#Plane_"<<i<<"-mesh\"/>";
			fs << "      </node>";
		}
		fs << "    </visual_scene>";
		fs << "  </library_visual_scenes>";
		fs << "  <scene>";
		fs << "    <instance_visual_scene url=\"#Scene\"/>";
		fs << "  </scene>";
		fs << "</COLLADA>";
		fs.release();
		return 0;
	}

	int Map::getMapFromFile(string filename)
	{
		FileStorage fs;
		fs.open(filename, FileStorage::READ);
		FileNode n = fs["Map"];
		if (n.type() != FileNode::SEQ)
			return -1;										// Map n'est pas une séquence

		FileNodeIterator it = n.begin(), it_end = n.end();  // Itérateur pour lire la séquence
		for (; it != it_end; ++it)
			cout << (string)*it << endl;

		fs.release();										// énoncer la fermeture
		return 0;
	}


	/* Calculation pour la raprésentation */
	Point3d Map::calculIntersection(
		Point3d planeVector, Point3d planePoint, 
		Point3d lineVector, Point3d linePoint){
			Point3d returnResult;
			double vp1, vp2, vp3, n1, n2, n3, v1, v2, v3, m1, m2, m3, t,vpt;
			vp1 = planeVector.x;
			vp2 = planeVector.y;
			vp3 = planeVector.z;
			n1 = planePoint.x;
			n2 = planePoint.y;
			n3 = planePoint.z;
			v1 = lineVector.x;
			v2 = lineVector.y;
			v3 = lineVector.z;
			m1 = linePoint.x;
			m2 = linePoint.y;
			m3 = linePoint.z;
			vpt = v1 * vp1 + v2 * vp2 + v3 * vp3;
			if (vpt == 0){
				returnResult=Point3d(-1,-1,-1); //si perpendiculaire, on retourne un verteur null
			}
			else{
				t = ((n1 - m1) * vp1 + (n2 - m2) * vp2 + (n3 - m3) * vp3) / vpt;
				returnResult.x = m1 + v1 * t;
				returnResult.y = m2 + v2 * t;
				returnResult.z = m3 + v3 * t;
			}
			return returnResult;
	}

	/* Sortie du modèle 3D final */
	int drawMap(){
		return 0;
	}
}