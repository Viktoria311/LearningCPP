#include <iostream>
#include <irrlicht.h>

int main()
{
	irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(800, 600), 32);

	if (!device)
		return 1;

	irr::video::IVideoDriver* driver = device->getVideoDriver();//драйвер видео для отображения
	irr::scene::ISceneManager* smgr = device->getSceneManager();//менеджер сцены. чтобы через взаимодействие с ней добавлять новые объекты
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();//для создания кнопок и пользовательского интерфейса

	// все 3d на покадровости основано

	irr::scene::IAnimatedMesh* mesh = smgr->getMesh("media/sydney.md2");
	mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);//чтобы оторажалось без света
	irr::scene::IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);// узел - это объект на сцене

	node->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
	smgr->addCameraSceneNode(0, irr::core::vector3df(0, 30, -40), irr::core::vector3df(0, 5, 0));//устанавливаем камеру подальше

	irr::scene::IMeshSceneNode* cube_node = smgr->addCubeSceneNode();
	cube_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	while (device->run()) {
		driver->beginScene();
		smgr->drawAll();

		driver->endScene();
	}



	device->drop();

	return 0;
}
