package com.example.cppclasstest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    val counter = Counter()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = counter.description()
    }

    fun increment(view: View) {
        counter.increment()
        sample_text.text = counter.description()
    }

    fun reset(view: View) {
        counter.count = 0
        sample_text.text = counter.description()
    }

    override fun onDestroy() {
        super.onDestroy()
        counter.delete()
    }

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
