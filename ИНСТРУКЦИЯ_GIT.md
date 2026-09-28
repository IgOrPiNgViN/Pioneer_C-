# Инструкция по работе с Git в Visual Studio

Краткая памятка для курса: как сохранять код и отправлять его на GitHub из Visual Studio.

Подробный урок с упражнениями: [уроки/урок_git_visual_studio.cpp](уроки/урок_git_visual_studio.cpp)

---

## Полезные ссылки

| Что | Ссылка |
|-----|--------|
| Что такое Git (официально) | [git-scm.com](https://git-scm.com/) |
| Документация Git | [git-scm.com/doc](https://git-scm.com/doc) |
| GitHub (регистрация) | [github.com](https://github.com/) |
| Git в Visual Studio | [Git experience in Visual Studio](https://learn.microsoft.com/ru-ru/visualstudio/version-control/git-with-visual-studio) |
| Клонирование репозитория | [Clone a repo in Visual Studio](https://learn.microsoft.com/ru-ru/visualstudio/version-control/git-clone-repository) |
| Публикация в GitHub | [Publish to GitHub](https://learn.microsoft.com/ru-ru/visualstudio/version-control/git-create-repository) |

---

## Зачем нужен Git

Git — система контроля версий. Она позволяет:

- сохранять историю изменений кода;
- возвращаться к рабочей версии;
- работать над проектом вдвоём и больше;
- хранить копию на GitHub (облако).

### Основные слова

| Термин | Смысл |
|--------|--------|
| Репозиторий | Папка проекта + история изменений |
| Commit | Сохранение изменений с сообщением |
| Branch (ветка) | Отдельная линия разработки |
| Push | Отправить коммиты на GitHub |
| Pull | Скачать чужие/новые коммиты с GitHub |
| Clone | Скачать весь репозиторий к себе |

---

## Подготовка

1. Установи [Visual Studio](ИНСТРУКЦИЯ_УСТАНОВКА_VISUAL_STUDIO.md) с нагрузкой C++.
2. Создай аккаунт на [GitHub](https://github.com/).
3. В Visual Studio при первом использовании Git войди в GitHub (**учётная запись** / Sign in).

---

## Вариант A. Создать репозиторий из своего проекта

1. Открой проект C++ в Visual Studio.
2. Меню **Git → Create Git Repository…** / **Создать репозиторий Git…**
3. Выбери папку проекта.
4. При желании отметь **Add a README** / **.gitignore** (для C++ можно выбрать шаблон VisualStudio).
5. Нажми **Create**.

### Первый коммит

1. Открой окно **Git Changes** (изменения Git).
2. В поле сообщения напиши, например: `Первая версия проекта`.
3. Нажми **Commit All** / **Зафиксировать все**.
4. Чтобы отправить на GitHub: **Push** / **Push to GitHub** / **Publish to GitHub** — создай удалённый репозиторий и дождись загрузки.

Официально: [Create a Git repository](https://learn.microsoft.com/ru-ru/visualstudio/version-control/git-create-repository).

---

## Вариант B. Склонировать готовый репозиторий (курс)

1. На GitHub открой страницу репозитория курса → кнопка **Code** → скопируй URL (HTTPS).
2. В Visual Studio: **Git → Clone Repository…**
3. Вставь URL, выбери папку на диске → **Clone**.

Официально: [Clone a repository](https://learn.microsoft.com/ru-ru/visualstudio/version-control/git-clone-repository).

---

## Обычная работа каждый день

1. Изменил код → файлы появятся в **Git Changes**.
2. Напиши понятное сообщение коммита (что сделал).
3. **Commit**.
4. **Push** — чтобы копия появилась на GitHub.

Примеры сообщений:

- `Урок 2: анкета и переменные`
- `Исправлена ошибка в цикле`
- `ДЗ: калькулятор`

---

## Ветки (кратко)

1. В **Git Changes** нажми на имя текущей ветки (часто `main` или `master`).
2. **New Branch** → имя, например `experiment`.
3. Работай в ветке → Commit → при необходимости Push.
4. Вернись на `main`, когда эксперимент не нужен.

Для начала курса достаточно одной ветки `main`.

---

## Частые проблемы

| Проблема | Что сделать |
|----------|-------------|
| Push просит войти | Войди в GitHub в Visual Studio |
| Конфликт при Pull | Visual Studio покажет конфликтные файлы — оставь нужный код, сохрани, сделай Commit |
| Нет меню Git | Убедись, что репозиторий создан (Create Git Repository) |
| Забыл Push | Код есть только на компьютере — нажми Push |

---

## Чеклист ученика

- [ ] Есть аккаунт GitHub  
- [ ] Проект в Git (есть история коммитов)  
- [ ] Сделан хотя бы один Push  
- [ ] На GitHub виден твой код  

---

## Связанные материалы

- [Установка Visual Studio](ИНСТРУКЦИЯ_УСТАНОВКА_VISUAL_STUDIO.md)
- [Русский язык в консоли](ИНСТРУКЦИЯ_РУССКИЙ_ЯЗЫК.md)
- [Главный README курса](README.md)
- [Урок Git (подробно, .cpp)](уроки/урок_git_visual_studio.cpp)
