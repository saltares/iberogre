/**
 * This file is part of IberOgre examples.
 *
 * IberOgre examples are free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License ad
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) ant later version.
 *
 * IberOgre examples are distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with IberOgre examples.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IBEROGRE_EJEMPLOS_OGRE_NODOS_INCLUDE_ESCENASIMPLE_H_
#define IBEROGRE_EJEMPLOS_OGRE_NODOS_INCLUDE_ESCENASIMPLE_H_

#include <map>

#include <OGRE/Ogre.h>
#include <OGRE/OgrePanelOverlayElement.h>
#include <OGRE/OgreTextAreaOverlayElement.h>

#include "aplicacionOgre.h"

//! Clase para crear una escena simple de ejemplo de animaciones con Ogre

/**
 * @author David Saltares Márquez
 * @file escenaSimple.h
 * @date 15-01-2011
 *
 * Clase descendiente de AplicacionOgre que se encarga de crear una escena
 * sencilla con una esfera a la que podemos cambiarle el material e información en overlays.
 */
class EscenaSimple: public AplicacionOgre {
    public:
        /**
         *  Constructor
         * 
         *  Se inicializa Ogre y crea una escena básica
         */
        EscenaSimple();
        
        /**
         *  Destructor
         * 
         *  Cierra Ogre y sale de la aplicación
         */
        ~EscenaSimple();
        
        /**
         *  Bucle principal
         * 
         *  Inicia el bucle principal, comienza a renderizar y capturar
         *  eventos hasta que el usuario cierra la aplicación
         */
         void buclePrincipal();
         
        bool keyPressed(const OIS::KeyEvent &arg);
    private:
        // Objetos Ogre
        Ogre::Camera* camara;
        Ogre::SceneNode* camaraNodo;
        Ogre::Viewport* viewport;
        Ogre::SceneManager* gestorEscena;

        // Fichero de recursos
        Ogre::String recursosCfg;
        
        // Nombre aplicación
        Ogre::String nombreVentana;
        
        // Escenario
        Ogre::SceneNode* escenarioNodo;
        Ogre::Entity* escenario;
        
        // Bola
        Ogre::SceneNode* bolaNodo;
        Ogre::Entity* bola;
        
        // Diccionario de teclas a nombres de material
        std::map<OIS::KeyCode, Ogre::String> teclasMateriales;

        // Luz
        Ogre::Light* luzPunto1;
        Ogre::Light* luzPunto2;
        Ogre::Light* luzPunto3;
        
        // Overlay
        Ogre::OverlayManager* gestorOverlay;
        Ogre::Overlay* overlay;
        Ogre::PanelOverlayElement* panelInfo;
        Ogre::TextAreaOverlayElement* tituloInfo;
        Ogre::TextAreaOverlayElement* fpsInfo;
        Ogre::TextAreaOverlayElement* materialInfo;
        
        // Control de tiempo
        Ogre::Timer* temporizador;
        Ogre::Real ultimoFrame;
        Ogre::Real deltaT;
    
        void prepararRecursos();
        void configurarSceneManager();
        void crearCamara();
        void crearEscena();
        void iniciarTemporizador();
        void iniciarDiccionarioMateriales();
        void configurarOverlay();
};

#endif  // IBEROGRE_EJEMPLOS_OGRE_NODOS_INCLUDE_ESCENASIMPLE_H_
