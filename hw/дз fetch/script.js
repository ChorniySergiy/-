// Получение списка записей
const URL = 'http://127.0.0.1:8000/'
fetch(URL + 'clean/records/list')
  .then(response => response.json())
  .then(data => {
    console.log(data);
    const recordsList = document.getElementById('records-list');
    let records_html = '';
    
    data.forEach(record => {
        records_html += `
        <div>
          <h2>${record.name}</h2>
          <p>${record.comment}</p>
          <p>${record.address}</p>
          <button onclick="deleteRecord(${record.id})">Удалить</button>
        </div>
      `;
    });
    recordsList.innerHTML = records_html;

  })
  .catch(error => console.error('Ошибка при получении списка записей:', error));


fetch(URL+'clean/services/list')
.then(response => response.json())
.then(data => {
    const serviceSelect = document.getElementById('service_id');
    data.forEach(service => {
      const option = document.createElement('option');
      option.value = service.id;
      option.text = service.title;
      serviceSelect.appendChild(option);
    });
  })
  .catch(error => console.error('Ошибка при получении списка услуг:', error));

function createRecord(e) {
    e.preventDefault()
    const formData = new FormData(document.getElementById('create-record-form'));
    fetch(URL+'clean/records/create', {
      method: 'POST',
      body: formData
    }).then(response => {

        console.log('Статус ответа:', response.status);
        if (!response.ok) {
          throw new Error('Error');
        }
        return response.json();
      }).then(data => 

        console.log('Запись создана:', data)

    ).catch(error => console.error('Ошибка при создании записи:', error));
}
function deleteRecord(id) {
    fetch(URL + `clean/records/delete/${id}`, {
      method: 'DELETE'
    })
    .then(response => {

        console.log('Статус ответа:', response.status);
        if (!response.ok) {
          throw new Error('Error');
        }
        return response.json();
      })
    .then(data => console.log('Запись удалена:', data))
    .catch(error => console.error('Ошибка при удалении записи:', error));
  }