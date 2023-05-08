/// \file scene.hpp
/// \brief Header file for the main scene
/// \author Jan Kalenda(xkalen07) & Tereza Kubincova(xkubin27)
/// \date 08.05.2023

#ifndef SCENE_HPP
#define SCENE_HPP
class GameScene;

#define BLOCK_SIZE 50

#include <ctime>
#include "player.hpp"
#include "ghost.hpp"
#include "Wall.hpp"
#include "lock.hpp"
#include "key.hpp"
#include "pause_menu.hpp"
#include "game.hpp"
#include "replayer.hpp"
#include "heart.hpp"
#include "victory.hpp"
#include "game_over.hpp"

/// structure representing a node during pathfinding
typedef struct path_node {
    QPoint pos;
    qreal cost;
    qreal heuristic;
    struct path_node *prev_node;
} PathNode;

class GameScene: public QGraphicsScene {
    Q_OBJECT
    public:
        /// Width of the scene from the map
        int width;

        /// Height of the scene from the map
        int height;

        /// indicate if selected mode is replay mode
		bool replay_mode;

        /// Constructor of the main scene
        /// \param filename file with the map
        /// \param game pointer to the game
        /// \param start indicates if the game is being started
        /// \param normal indicates if the game is in normal mode
        /// \param replay indicates if the game is in replay mode
        GameScene(const char filename[], Game *game, bool start, bool normal, bool replay);

        /// Destructor of the main scene
        ~GameScene();

        /// Handles mouse click events
        /// \param mouse_event Qt mouse event
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouse_event) override;

        /// Handles key press events
        /// \param event Qt key event
        virtual void keyPressEvent(QKeyEvent *event) override;

        /// Sets the view of the scene
        /// \param view pointer to the view
        void set_view(QGraphicsView *view);

    public slots:
        /// Monitors the game state
        void monitor_game_state ();

    private:
        /// Player of the game
        Player *player;

        /// Vector of ghosts
        std::vector <Ghost *> ghosts;

        /// Global timer
        QTimer * timer;

        /// View of the scene
        QGraphicsView *view;

        /// Logging file
        std::ofstream log_file;

		/// Game object
		Game *game;

		/// Replayer object
		Replayer *replayer;

		/// Key object
	    Key *key;

		/// Step counter
		QGraphicsTextItem *text;

		/// Heart object
		Heart *heart;

        /// Logs the game state
        void log();

        /// Recalculates the path
        /// \param closed closed nodes
        /// \param start_point starting point
        /// \param path resulting path
        void regenerate_path(QList <PathNode *> &closed, PathNode *&start_point, QList <QPoint> &path);

        /// Finds the shortest path
        /// \param start starting point
        /// \param stop ending point
        /// \param path resulting path
        /// \param iter iterator to the path
        void shortest_path (QPoint start, QPoint stop, QList<QPoint> &path, QList<QPoint>::iterator &iter);

        /// Generates the scene from a text file
        /// \param filename file with the map
		void generate_scene_from_txt (std::ifstream &file);

        /// Calculates the distance between two points
        /// \param start starting point
        /// \param stop ending point
        /// \return distance between the points
        qreal distance_between_points(const QPoint &start, const QPoint &stop);

        /// Generates a random position
        QPoint random_pos();

        /// Checks if a point is in a list
        /// \param open list of points
        /// \param s point to check
        int contains(QList<PathNode *> open, PathNode *s);

        /// Checks if a point is valid
        /// \param pos point to check
        bool is_valid_move(QPoint &pos);

		/// Replays a game
		/// \param log_file file with the log
		void replay(const char log_file[]);

		/// Updates the step counter
		void update_steps();

		/// Initializes the log file
		/// \param file file with the log
		void init_log(std::ifstream &file);

    private slots:
        /// Handles the game over event
        void game_over();

        /// Handles the game win event
        void game_win();
};

#endif // SCENE_HPP
