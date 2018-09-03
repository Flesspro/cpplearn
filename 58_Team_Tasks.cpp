#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
	  return db.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
	  db[person][TaskStatus::NEW]++;
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже

  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {

	  vector<TaskStatus> status_names = {TaskStatus::NEW, TaskStatus::IN_PROGRESS,
			  TaskStatus::TESTING, TaskStatus::DONE};

	  int ctr = task_count;
	  int ctr_prev = 0;
	  int ctr_current = 0;

	  TasksInfo updated_tasks, untouched_tasks;

	  for (auto stat : status_names) {
		  // Updating tasks from previous category to the current one
		  if (ctr_prev > 0) {
			  updated_tasks[stat] = ctr_prev;
			  ctr_prev = 0;
		  }

		  // Find how many tasks of the current category need to be updated
		  ctr_current = min(db[person][stat], ctr);

		  // Calculating untouched tasks of the current category
		  if (db[person][stat] > ctr_current && stat != TaskStatus::DONE) {
			  untouched_tasks[stat] = db[person][stat] - ctr_current;
		  }

		  // Reducing ctr to reflect updated tasks
		  if (ctr_current > 0) {
			  ctr -= ctr_current;
		  }

		  ctr_prev = ctr_current;
	  }

	  for (auto stat : status_names) {
		  if (stat != TaskStatus::DONE) {
			  db[person][stat] = updated_tasks[stat] + untouched_tasks[stat];
		  } else {
			  db[person][stat] += updated_tasks[stat];
		  }

		  cleanup (db[person], stat);
		  cleanup (updated_tasks, stat);
		  cleanup (untouched_tasks, stat);

	  }

	  return tie(updated_tasks, untouched_tasks);
  }

  void cleanup (TasksInfo& tasks, const TaskStatus& stat) {
	  if (tasks[stat] == 0) {
	      tasks.erase(stat);
	  }
  }

private:
  map<string, TasksInfo> db;
};

// Code provided for testing:

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;

  for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  };

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
		  tasks.PerformPersonTasks("Alice", 5);
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
		  tasks.PerformPersonTasks("Alice", 5);
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
		  tasks.PerformPersonTasks("Alice", 1);
  PrintTasksInfo(untouched_tasks);

  for (int i = 0; i < 5; ++i) {
	tasks.AddNewTask("Alice");
  }


  tie(updated_tasks, untouched_tasks) =
		  tasks.PerformPersonTasks("Alice", 2);
  PrintTasksInfo(untouched_tasks);

  untouched_tasks = tasks.GetPersonTasksInfo("Alice") ;
  PrintTasksInfo(untouched_tasks);

  return 0;
}

