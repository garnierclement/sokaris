# Cascade classifier training guide

[Source (OpenCV)][opencvdoc]

[opencvdoc]: http://docs.opencv.org/doc/user_guide/ug_traincascade.html

## Vocabulary

- classifier
- testing samples : testing samples are images which include positives in negative background images and locations of positives are known in the images.
- train samples
- cascade

## Important notes

OpenCV built-in softwares to use :

- `opencv_createsamples` used to create dataset of positive samples and produces a *.vec file (binary images)
- `opencv_traincascade`

## Main steps

1. Preparation of training data (with `opencv_createsamples`)  
	* creation of positive samples  
	* creation of test samples
2. Running the training application (with `opencv_traincascade`)

## Preparation

In order to train a classifier, we need 2 types of samples :

- positives samples (images with detected objects)
	* created using `opencv_createsamples`
	* created from a **single image** or from a **set of marked up images** 
	* **large set** is required (100 ~ 10000) with different faces (race, age, emotions, beards, glasses …)
	* can apply **perspective transformations**
	* the goal is to **create .vec file**
	
- negative samples (arbitrary images without detected objects)
	* created **manually**  
	* also called ***background*** or *background images*  
	* images are enumerated in file with **each line containing an image filename** (and its relative path to the description file) 
	* **different size** but bigger than the *training window*
	* directory structure
	
	```
	/negative  
		neg1.jpg
		neg2.jpg  
		...  
	bg.txt  
	```
	
	* `bg.txt` looks like the following
	
	
	```
	negative/neg1.jpg  
	negative/neg2.jpg  
	...  
	```

### Positives samples

#### Single picture

We can select a single image and create a set of positives images using `opencv_createsamples` and applying :

- rotation : `-maxxangle`, `-maxyangle`, `-maxzangle`
- placing on arbitrary background
- intensity : `-bgcolor`, `-bgthresh`, pixels having intensity between `[bgcolor-bgthresh;bgcolor+bgthresh]` are interpreted as transparent

Obtained images are **stored in the .vec file**. To display the result, we can use the following command :
`opencv_createsamples -vec vecfile.vec -show` (use space bar to see generated images and `ESC` to quit)

#### Set of marked up images

- Directory structure 

```
/positive
	pos1.jpg
	pos2.jpg
	…
info.dat
```

- `info.dat` looks like

```
positive/pos1.jpg  1  140 100 45 45
positive/pos2.jpg  2  100 200 50 50   50 30 25 25
...
```
- use option `-info`
- images are resized to target samples size and stored in output .vec file. No distortion is applied, so the only affecting arguments are `-w`, `-h`, `-show` and `-num`

## Training





	

