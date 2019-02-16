package com.example.ciprian.exam

import android.arch.lifecycle.Observer
import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.View
import com.example.ciprian.exam.adapters.FifthAdapter
import com.example.ciprian.exam.adapters.MainAdapter
import com.example.ciprian.exam.domain.Message
import kotlinx.android.synthetic.main.activity_first.*
import kotlinx.android.synthetic.main.activity_sixth.*

class SixthActivity : AppCompatActivity(),MyCallback {
    var adapter: FifthAdapter? = null
    lateinit var name:String
    private var recyclerView: View? = null
    private var manager: Manager? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sixth)
        progressSixth.visibility = View.GONE
        manager = Manager(application as MyApp)
        get_button.setOnClickListener{
            name = user_name.text.toString()
            if(name != ""){
                progressSixth.visibility = View.VISIBLE
                manager!!.getPrivates(name,progressSixth,this,this)
            }
        }
        recyclerView = findViewById(R.id.private_list)
        setupRecyclerView(recyclerView as RecyclerView)

    }

//    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
//        loadEvents()
//    }

//    fun loadEvents(): Boolean {
//        progressFirst.visibility = View.VISIBLE
//        val connectivity = manager!!.networkConnectivity(applicationContext)
//        if (!connectivity) {
//            showError("There is no connection")
//        } else {
//            manager!!.loadPublic(progressFirst, this, this)
//        }
//
//        return connectivity
//    }

    override fun clear() {

    }

    override fun showError(message: String) {
        progressFirst.visibility = View.GONE
        Snackbar.make(recyclerView!!, message, Snackbar.LENGTH_INDEFINITE)
                .setAction("RETRY") { manager!!.getPrivates(name,progressSixth,this,this) }.show()
    }

    private fun setupRecyclerView(recyclerView: RecyclerView) {
        adapter = FifthAdapter()
        (application as MyApp).db.messageDao.bookmarks
                .observe(this, Observer { bikes ->
                    if (bikes != null) {
                        adapter!!.setData(bikes as MutableList<Message>,progressSixth,application as MyApp,this,this)
                    }
                })

        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.adapter = adapter
//    }


    }

}
