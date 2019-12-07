#include <iostream>
#include <tuple>
#include <map>
#include <vector>

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
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return PersonalTasks.at(person);
    };

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
        PersonalTasks[person][TaskStatus::NEW] += 1;
    };

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count){
        TasksInfo changed, untached;
        if (PersonalTasks.count(person) == 0){
            return tie(changed, untached);
        }
        int n = 0;
        int n1 = 0;
        vector<TaskStatus> statistic = {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE};
        for(auto key : statistic) {
            if (task_count > PersonalTasks[person][key]) {
                task_count -= PersonalTasks[person][key];
                n1 = PersonalTasks[person][key];
                PersonalTasks[person][key] = n;
                changed[key] = n;
                n = n1;
            } else {
                untached[key] = PersonalTasks[person][key] - task_count;
                changed[key] = n;
                PersonalTasks[person][key] += n - task_count;
                n = task_count;
                task_count = 0;
            }
            if (PersonalTasks[person][key] == 0){
                PersonalTasks[person].erase(key);
            }
            if (untached[key] == 0){
                untached.erase(key);
            }
            if (changed[key] == 0){
                changed.erase(key);
            }
        }

        if (untached.count(TaskStatus::DONE)){
            untached.erase(TaskStatus::DONE);
        }

        if (n != 0){
            PersonalTasks[person][TaskStatus::DONE] += n;
        }
        return tie(changed, untached);
    };


private:
    map<string, TasksInfo> PersonalTasks;
};

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
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}

