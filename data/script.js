function resetForm() {
  document.getElementById('configForm').reset();
  toggleStaticIPFields(); // Uzreiz paslēpj IP laukus, ja ir DHCP
}

window.addEventListener('load', () => {
  fetch('/config')
    .then(res => res.json())
    .then(data => {
      for (let key in data) {
        const field = document.querySelector(`[name="${key}"]`);
        if (field) {
          if (field.type === "checkbox") {
            field.checked = data[key];
          } else {
            field.value = data[key];
          }
        }
      }
      toggleStaticIPFields();
    })
    .catch(err => {
      console.error("Neizdevās ielādēt konfigurāciju:", err);
    });
});

document.getElementById('configForm').addEventListener('submit', function (e) {
  e.preventDefault();
  const form = new FormData(this);
  const data = Object.fromEntries(form.entries());

  data.useDHCP = document.querySelector('[name="useDHCP"]').checked;
  data.mqttPort = parseInt(data.mqttPort);
  data.partition = parseInt(data.partition);
  data.defaultPartition = parseInt(data.defaultPartition);
  data.maxZonesDefault = parseInt(data.maxZonesDefault);
  data.maxRelays = parseInt(data.maxRelays);
  data.Ddebug = parseInt(data.Ddebug);

  fetch('/save', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(data)
  }).then(res => {
    if (res.ok) alert('Konfigurācija saglabāta! Ierīce tiks restartēta...');
    else alert('Kļūda saglabājot konfigurāciju!');
  });
});

function toggleStaticIPFields() {
  const useDHCP = document.querySelector('[name="useDHCP"]').checked;
  document.querySelectorAll('.static-ip').forEach(el => {
    el.style.display = useDHCP ? 'none' : 'block';
  });
}


function resetDevice() {
  if (confirm("Vai tiešām vēlies dzēst visus iestatījumus un pārstartēt ierīci?")) {
    fetch('/reset', {
      method: 'POST',
    }).then(res => {
      if (res.ok) alert("Iestatījumi dzēsti. Ierīce tiek pārstartēta!");
      else alert("Neizdevās veikt rūpnīcas atiestatīšanu.");
    });
  }
}

document.addEventListener('DOMContentLoaded', () => {
  const dhcpCheckbox = document.querySelector('[name="useDHCP"]');
  if (dhcpCheckbox) {
    dhcpCheckbox.addEventListener('change', toggleStaticIPFields);
  }
});


