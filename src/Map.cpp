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

	int Map::getListCamerasSize(){
		return this->listCameras.size();
	}

	int Map::getListPlanesSize(){
		return this->listPlanes.size();
	}

	int Map::getListGazesSize(){
		return this->listGazes.size();
	}


	/* Sortie du modèle 3D final */
	int Map::writeResultToFile(string filename, double energy, double posX_observator, 
		double posY_observator, double posZ_observator, double angleX_observator, 
		double angleY_observator, double angleZ_observator)
	{
		int number_Spot = this->listGazes.size();
		int number_Plane = this->listPlanes.size();
		int i=0;
		ofstream fs(filename);
		fs << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
		fs << "<COLLADA xmlns=\"http://www.collada.org/2005/11/COLLADASchema\" version=\"1.4.1\">\n";
		fs << "  <asset>\n";
		fs << "    <contributor>\n";
		fs << "      <author>Sokaris</author>\n";
		fs << "      <authoring_tool>Blender 2.67.0 r56533</authoring_tool>\n";
		fs << "    </contributor>\n";
		fs << "    <created>2013-05-27T13:29:29</created>\n";
		fs << "    <modified>2013-05-27T13:29:29</modified>\n";
		fs << "    <unit name=\"meter\" meter=\"1\"/>\n";
		fs << "    <up_axis>Z_UP</up_axis>\n";
		fs << "  </asset>\n";
		fs << "  <library_cameras>\n";
		fs << "    <camera id=\"Camera-camera\" name=\"Observator\">\n";
		fs << "      <optics>\n";
		fs << "        <technique_common>\n";
		fs << "          <perspective>\n";
		fs << "            <xfov sid=\"xfov\">90</xfov>\n";
		fs << "            <aspect_ratio>1.3333</aspect_ratio>\n";
		fs << "            <znear sid=\"znear\">0.1</znear>\n";
		fs << "            <zfar sid=\"zfar\">100</zfar>\n";
		fs << "          </perspective>\n";
		fs << "        </technique_common>\n";
		fs << "      </optics>\n";
		fs << "    </camera>\n";
		fs << "  </library_cameras>\n";
		fs << "  <library_lights>\n";
		for(i=0; i<number_Spot; i++){
			fs << "    <light id=\"Spot_" << i << "-light\" name=\"Spot." <<i<< "\">\n";
			fs << "      <technique_common>\n";
			fs << "        <spot>\n";
			fs << "          <color sid=\"color\">1 1 1</color>\n";
			fs << "          <constant_attenuation>1</constant_attenuation>\n";
			fs << "          <linear_attenuation>0</linear_attenuation>\n";
			fs << "          <quadratic_attenuation>0.001599967</quadratic_attenuation>\n";
			fs << "          <falloff_angle sid=\"fall_off_angle\">15</falloff_angle>\n";
			fs << "          <falloff_exponent sid=\"fall_off_exponent\">0.15</falloff_exponent>\n";
			fs << "        </spot>\n";
			fs << "      </technique_common>\n";
			fs << "      <extra>\n";
			fs << "        <technique profile=\"blender\">\n";
			fs << "          <clipend>40</clipend>\n";
			fs << "          <clipsta>0.5</clipsta>\n";
			fs << "          <dist sid=\"blender_dist\">25</dist>\n";
			fs << "          <energy sid=\"blender_energy\">"<<energy<<"</energy>\n";
			fs << "          <falloff_type>0</falloff_type>\n";
			fs << "          <spotblend>0.15</spotblend>\n";
			fs << "          <spotsize>15</spotsize>\n";
			fs << "          <spread>1</spread>\n";
			fs << "          <type>2</type>\n";
			fs << "        </technique>\n";
			fs << "      </extra>\n";
			fs << "    </light>\n";
		}
		fs << "  </library_lights>\n";
		fs << "  <library_images/>\n";
		fs << "  <library_geometries>\n";
		for (i=0; i<number_Plane; i++){
			fs << "    <geometry id=\"Plane_"<<i<<"-mesh\" name=\"Plane."<<i<<"\">\n";
			fs << "      <mesh>\n";
			fs << "        <source id=\"Plane_"<<i<<"-mesh-positions\">\n";
			fs << "          <float_array id=\"Plane_"<<i<<"-mesh-positions-array\" count=\"12\">1 -1 0 -1 -1 0 1 1 0 -1 1 0</float_array>\n";
			fs << "          <technique_common>\n";
			fs << "            <accessor source=\"#Plane_"<<i<<"-mesh-positions-array\" count=\"4\" stride=\"3\">\n";
			fs << "              <param name=\"X\" type=\"float\"/>\n";
			fs << "              <param name=\"Y\" type=\"float\"/>\n";
			fs << "              <param name=\"Z\" type=\"float\"/>\n";
			fs << "            </accessor>\n";
			fs << "          </technique_common>\n";
			fs << "        </source>\n";
			fs << "        <source id=\"Plane_"<<i<<"-mesh-normals\">\n";
			fs << "          <float_array id=\"Plane_"<<i<<"-mesh-normals-array\" count=\"6\">0 0 1 0 0 1</float_array>\n";
			fs << "          <technique_common>\n";
			fs << "            <accessor source=\"#Plane_"<<i<<"-mesh-normals-array\" count=\"2\" stride=\"3\">\n";
			fs << "              <param name=\"X\" type=\"float\"/>\n";
			fs << "              <param name=\"Y\" type=\"float\"/>\n";
			fs << "              <param name=\"Z\" type=\"float\"/>\n";
			fs << "            </accessor>\n";
			fs << "          </technique_common>\n";
			fs << "        </source>\n";
			fs << "        <vertices id=\"Plane_"<<i<<"-mesh-vertices\">\n";
			fs << "          <input semantic=\"POSITION\" source=\"#Plane_"<<i<<"-mesh-positions\"/>\n";
			fs << "        </vertices>\n";
			fs << "        <polylist count=\"2\">\n";
			fs << "          <input semantic=\"VERTEX\" source=\"#Plane_"<<i<<"-mesh-vertices\" offset=\"0\"/>\n";
			fs << "          <input semantic=\"NORMAL\" source=\"#Plane_"<<i<<"-mesh-normals\" offset=\"1\"/>\n";
			fs << "          <vcount>3 3 </vcount>\n";
			fs << "          <p>1 0 0 0 2 0 3 1 1 1 2 1</p>\n";
			fs << "        </polylist>\n";
			fs << "      </mesh>\n";
			fs << "      <extra><technique profile=\"MAYA\"><double_sided>1</double_sided></technique></extra>\n";
			fs << "    </geometry>\n";
			fs << "\n";
		}
		fs << "  </library_geometries>\n";
		fs << "  <library_controllers/>\n";
		fs << "  <library_visual_scenes>\n";
		fs << "    <visual_scene id=\"Scene\" name=\"Scene\">\n";
		fs << "      <node id=\"Camera\" name=\"Observator\" type=\"NODE\">\n";
		fs << "        <translate sid=\"location\">"<<posX_observator<<" "<<posY_observator<<" "<<posZ_observator<<"</translate>\n";
		fs << "        <rotate sid=\"rotationZ\">0 0 1 "<<angleZ_observator<<"</rotate>\n";
		fs << "        <rotate sid=\"rotationY\">0 1 0 "<<angleY_observator<<"</rotate>\n";
		fs << "        <rotate sid=\"rotationX\">1 0 0 "<<angleX_observator<<"</rotate>\n";
		fs << "        <scale sid=\"scale\">1 1 1</scale>\n";
		fs << "        <instance_camera url=\"#Camera-camera\"/>\n";
		fs << "      </node>\n";
		for(i=0; i<number_Spot; i++){
			fs << "      <node id=\"Spot_"<<i<<"\" name=\"Spot_"<<i<<"\" type=\"NODE\">\n";
			fs << "        <translate sid=\"location\">"<<this->listGazes[i]->getPosition().x<<" "
				<<this->listGazes[i]->getPosition().y<<" "<<this->listGazes[i]->getPosition().z<<"</translate>\n";
			fs << "        <rotate sid=\"rotationZ\">0 0 1 "<<this->listGazes[i]->getAngles().z<<"</rotate>\n";
			fs << "        <rotate sid=\"rotationY\">0 1 0 "<<this->listGazes[i]->getAngles().y<<"</rotate>\n";
			fs << "        <rotate sid=\"rotationX\">1 0 0 "<<this->listGazes[i]->getAngles().x<<"</rotate>\n";
			fs << "        <scale sid=\"scale\">1 1 1</scale>\n";
			fs << "        <instance_light url=\"#Spot_"<<i<<"-light\"/>\n";
			fs << "      </node>\n";
		}
		for(i=0;i<number_Plane;i++){
			fs << "      <node id=\"Plane_"<<i<<"\" name=\"Plane_"<<i<<"\" type=\"NODE\">\n";
			fs << "        <translate sid=\"location\">"<<this->listPlanes[i]->point.x<<" "
				<<this->listPlanes[i]->point.y<<" "<<this->listPlanes[i]->point.z<<"</translate>\n";
			fs << "        <rotate sid=\"rotationZ\">0 0 1 "<<this->listPlanes[i]->angles.z<<"</rotate>\n";
			fs << "        <rotate sid=\"rotationY\">0 1 0 "<<this->listPlanes[i]->angles.y<<"</rotate>\n";
			fs << "        <rotate sid=\"rotationX\">1 0 0 "<<this->listPlanes[i]->angles.x<<"</rotate>\n";
			fs << "        <scale sid=\"scale\">"<<this->listPlanes[i]->width<<" "<<this->listPlanes[i]->height<<" 1</scale>\n";
			fs << "        <instance_geometry url=\"#Plane_"<<i<<"-mesh\"/>\n";
			fs << "      </node>\n";
		}
		fs << "    </visual_scene>\n";
		fs << "  </library_visual_scenes>\n";
		fs << "  <scene>\n";
		fs << "    <instance_visual_scene url=\"#Scene\"/>\n";
		fs << "  </scene>\n";
		fs << "</COLLADA>\n";
		fs.close();
		return 0;
	}

	int Map::readCamerasFromFile(string filename)
	{
		string str_readfile = filename;
		ifstream f_input;
		f_input.open(str_readfile.c_str());
		if(!f_input)
		{
			return -1;
		}
		string str_output;
		while(getline(f_input,str_output))
		{
			Camera* c = new Camera();
			if (c->setFromString(str_output)==-1){
				return -2;
			}
			this->listCameras.push_back(c);
		}
		return 0;
	}

	int Map::readGazesFromFile(string filename)
	{
		string str_readfile = filename;
		ifstream f_input;
		f_input.open(str_readfile.c_str());
		if(!f_input)
		{
			return -1;
		}
		string str_output;
		while(getline(f_input,str_output))
		{
			Gaze* g = new Gaze();
			if (g->setFromString(str_output)==-1){
				return -2;
			}
			this->listGazes.push_back(g);
		}
		return 0;
	}

	int Map::readPlanesFromFile(string filename){
		// TODO
		return 0;
	}
	
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
				returnResult=Point3d(); //si perpendiculaire, on retourne un verteur null
			}
			else{
				t = ((n1 - m1) * vp1 + (n2 - m2) * vp2 + (n3 - m3) * vp3) / vpt;
				returnResult.x = m1 + v1 * t;
				returnResult.y = m2 + v2 * t;
				returnResult.z = m3 + v3 * t;
			}
			return returnResult;
	}
}